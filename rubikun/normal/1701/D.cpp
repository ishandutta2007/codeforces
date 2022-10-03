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
const int mod=1000000007,MAX=400005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> L(N),R(N);
        vector<vector<pair<int,int>>> que(N+3,vector<pair<int,int>>());
        for(int i=0;i<N;i++){
            int x;cin>>x;
            //ceil((a+1)/(b+1))
            L[i]=(i+1+1+x)/(x+1);
            if(x==0) R[i]=N;
            else R[i]=(i+1)/x;
            que[L[i]].push_back(mp(R[i],i));
        }
        
        //for(int i=0;i<N;i++) cout<<L[i]<<" "<<R[i]<<endl;
        
        vector<int> ans(N);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
        
        for(int i=1;i<=N;i++){
            for(auto a:que[i]){
                PQ.push(a);
            }
            auto x=PQ.top();PQ.pop();
            ans[x.se]=i;
        }
        
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}