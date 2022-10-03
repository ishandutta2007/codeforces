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
const int mod=998244353,MAX=100005,INF=1<<29;

vector<int> G[MAX];
ll S[MAX],A[MAX];
int par[MAX];
ll ans=0;

void solve(ll l,ll r,ll m){
    ans+=A[m]*(m-l+1)*(r-m);
    for(int to:G[m]){
        if(to<m){
            solve(l,m,to);
        }else{
            solve(m+1,r,to);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>S[i];
        if(i) A[i-1]=abs(S[i]-S[i-1]);
    }
    
    while(Q--){
        ll l,r;cin>>l>>r;l--;r--;
        for(int i=0;i<N;i++){
            G[i].clear();
            par[i]=-1;
        }
        ans=0;
        
        vector<int> ST;
        for(int i=l;i<r;i++){
            int p=-1;
            while(!ST.empty()&&A[i]>A[ST.back()]){
                p=ST.back();
                ST.pop_back();
            }
            if(p!=-1){
                par[p]=i;
            }
            if(!ST.empty()){
                par[i]=ST.back();
            }
            ST.push_back(i);
        }
        int ro=-1;
        for(int i=l;i<r;i++){
            if(par[i]==-1) ro=i;
            else G[par[i]].push_back(i);
        }
        
        solve(l,r,ro);
        
        cout<<ans<<"\n";
    }
}