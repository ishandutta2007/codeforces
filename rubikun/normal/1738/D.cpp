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
const int mod=998244353,MAX=100005,INF=1<<30;

vector<int> G[MAX];
int dis[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N;cin>>N;
        vector<int> A(N+1);
        for(int i=1;i<=N;i++) cin>>A[i];
        
        for(int i=0;i<=N+3;i++) G[i].clear();
        
        for(int i=1;i<=N;i++){
            G[A[i]].push_back(i);
        }
        
        for(int i=0;i<=N+1;i++){
            sort(all(G[i]),[](int a,int b){
                return si(G[a])<si(G[b]);
            });
        }
        
        queue<int> Q;
        for(int i=0;i<=N+1;i++) dis[i]=INF;
        if(si(G[0])){
            dis[0]=0;
            Q.push(0);
        }
        if(si(G[N+1])){
            dis[N+1]=0;
            Q.push(N+1);
        }
        
        vector<int> ans;
        
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int to:G[u]){
                chmin(dis[to],dis[u]+1);
                ans.push_back(to);
                Q.push(to);
            }
        }
        
        if(si(G[0])){
            int mi=INF;
            for(int i=1;i<=N;i++){
                if(dis[i]%2==1) chmin(mi,i);
            }
            cout<<mi-1<<"\n";
            for(int a:ans) cout<<a<<" ";
            cout<<"\n";
        }else{
            int mi=-INF;
            for(int i=1;i<=N;i++){
                if(dis[i]%2==1) chmax(mi,i);
            }
            cout<<mi<<"\n";
            for(int a:ans) cout<<a<<" ";
            cout<<"\n";
        }
    }
}