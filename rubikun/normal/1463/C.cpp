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
const int INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<pair<ll,ll>> T(N);
        for(int i=0;i<N;i++){
            cin>>T[i].fi>>T[i].se;
        }
        
        T.push_back(mp(1LL<<60,0));
        
        int ans=0;
        
        ll nowp=0,nowt=0;
        int i=0;
        
        while(i<N){
            nowt=T[i].fi;
            ll need=abs(nowp-T[i].se);
            if(nowt+need<=T[i+1].fi){
                nowt+=need;
                nowp=T[i].se;
                ans++;
                i++;
                continue;
            }
            
            int j=i+1;
            
            while(j<N&&T[j].fi<nowt+need){
                ll p1=nowp,p2=nowp;
                if(T[i].se>nowp){
                    p1+=T[j].fi-nowt;
                    p2+=T[j+1].fi-nowt;
                    chmin(p2,T[i].se);
                    
                    if(p1<=T[j].se&&T[j].se<=p2) ans++;
                }else{
                    p1-=T[j].fi-nowt;
                    p2-=T[j+1].fi-nowt;
                    chmax(p2,T[i].se);
                    
                    if(p2<=T[j].se&&T[j].se<=p1) ans++;
                }
                
                j++;
            }
            
            nowp=T[i].se;
            
            i=j;
        }
        
        cout<<ans<<"\n";
    }
}