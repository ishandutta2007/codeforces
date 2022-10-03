#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<40;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(2*N),pos(N);
    
    set<int> SE;
    
    
    for(int i=0;i<2*N;i++){
        char c;cin>>c;
        if(c=='+'){
            A[i]=-1;
            SE.insert(-i);
        }else{
            int x;cin>>x;
            A[i]=-x;
            pos[x-1]=i;
        }
    }
    
    
    for(int i=0;i<N;i++){
        auto it=SE.lower_bound(-pos[i]);
        if(it==SE.end()){
            cout<<"NO"<<endl;
            return 0;
        }else{
            A[-(*it)]=i+1;
            SE.erase(it);
        }
    }
    
    //for(int i=0;i<2*N;i++) cout<<A[i]<<endl;
    
    priority_queue<int,vector<int>,greater<int>> PQ;
    
    for(int i=0;i<2*N;i++){
        if(A[i]>0){
            PQ.push(A[i]);
        }else{
            if(PQ.empty()){
                cout<<"NO"<<endl;
                return 0;
            }
            int x=PQ.top();PQ.pop();
            
            if(x!=-A[i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"YES"<<endl;
    
    for(int i=0;i<2*N;i++){
        if(A[i]>0) cout<<" "<<A[i];
    }
    cout<<endl;
}