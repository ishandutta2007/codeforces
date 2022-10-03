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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),B(N);
    set<int> SE;
    map<int,int> MA;
    
    for(int i=0;i<=200000;i++) SE.insert(i);
    for(int i=0;i<N;i++){
        cin>>A[i];
        SE.erase(A[i]);
        MA[A[i]]++;
    }
    
    int now=0;
    
    for(int i=0;i<N;i++){
        auto it=SE.begin();
        B[i]=*it;
        SE.erase(B[i]);
        MA[A[i]]--;
        if(MA[A[i]]==0) SE.insert(A[i]);
    }
    
    SE.clear();
    
    for(int i=0;i<=200000;i++) SE.insert(i);
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        SE.erase(B[i]);
        if(*SE.begin()!=A[i]) ok=false;
    }
    
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=0;i<N;i++) cout<<B[i]<<" ";
    cout<<endl;
    
    
}