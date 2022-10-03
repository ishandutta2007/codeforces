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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> G[MAX];
int when[MAX],par[MAX];

int s;

void solve(int u,int p,int f){
    if(when[u]>=0){
        cout<<"Possible\n";
        vector<int> A,B;
        int now=u;
        while(now!=-1){
            A.push_back(now);
            now=par[now];
        }
        B.push_back(u);
        now=p;
        while(now!=-1){
            B.push_back(now);
            now=par[now];
        }
        reverse(all(A));
        reverse(all(B));
        cout<<si(A)<<"\n";
        for(int a:A) cout<<a+1<<" ";
        cout<<"\n";
        cout<<si(B)<<"\n";
        for(int a:B) cout<<a+1<<" ";
        cout<<"\n";
        exit(0);
    }
    when[u]=f;
    par[u]=p;
    for(int to:G[u]){
        if(when[to]==f) continue;
        if(to==s) continue;
        solve(to,u,f);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M>>s;s--;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
    }
    if(si(G[s])<=1){
        cout<<"Impossible\n";
        return 0;
    }
    memset(when,-1,sizeof(when));
    memset(par,-1,sizeof(par));
    
    for(int to:G[s]){
        solve(to,s,to);
    }
    
    cout<<"Impossible\n";
}