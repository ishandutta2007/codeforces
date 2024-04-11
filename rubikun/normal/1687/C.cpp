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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N,M;cin>>N>>M;
        vector<ll> A(N),B(N),rui(N+1);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        for(int i=1;i<=N;i++){
            rui[i]=rui[i-1]+A[i-1]-B[i-1];
        }
        
        set<int> NG;
        
        for(int i=0;i<=N;i++){
            if(rui[i]) NG.insert(i);
        }
        
        for(int i=0;i<=N;i++) G[i].clear();
        
        vector<pair<int,int>> E(M);
        vector<int> cn(M);
        queue<pair<int,int>> Q;
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;a--;
            
            E[i]=mp(a,b);
            cn[i]+=2;
            if(rui[a]==0) cn[i]--;
            else G[a].push_back(i);
            if(rui[b]==0) cn[i]--;
            else G[b].push_back(i);
            if(cn[i]==0){
                Q.push(mp(a,b));
            }
        }
        
        if(rui.back()){
            cout<<"NO\n";
            continue;
        }
        
        while(!Q.empty()){
            auto u=Q.front();Q.pop();
            auto it=NG.upper_bound(u.fi);
            while(it!=NG.end()&&(*it)<u.se){
                for(int x:G[(*it)]){
                    cn[x]--;
                    if(cn[x]==0) Q.push(E[x]);
                }
                it=NG.erase(it);
            }
        }
        
        if(NG.empty()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}