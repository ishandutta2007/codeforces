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
const int mod=998244353,MAX=5000005,INF=1<<30;

bool deta[MAX];
int cn[MAX];
int mi[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        for(int i=0;i<=M;i++){
            deta[i]=false;
            cn[i]=0;
            mi[i]=i;
        }
        int s=INF,t=-INF;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            chmin(s,x);
            chmax(t,x);
            deta[x]=true;
            cn[x]=true;
        }
        
        ll ans=t-s;
        int ma=t;
        
        for(ll i=t;i>=1;i--){
            for(ll j=i*i;j<=t;j+=i){
                if(deta[j]) cn[mi[j]]--;
                chmin(mi[j],mi[j/i]);
                if(deta[j]) cn[mi[j]]++;
            }
            
            while(cn[ma]==0) ma--;
            if(i<=s) chmin(ans,ma-i);
        }
        
        cout<<ans<<"\n";
        
        
    }
}