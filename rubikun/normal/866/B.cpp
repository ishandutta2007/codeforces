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
    
    ll N,S;cin>>N>>S;
    priority_queue<pair<ll,ll>> PQ;
    ll sum=0,ans=0,now=0;
    for(int i=0;i<N;i++){
        ll a,b,c;cin>>a>>b>>c;
        sum+=a;
        now+=a*b;
        PQ.push(mp(c-b,a));
    }
    ans=now;
    
    ll need=(sum+S-1)/S;
    
    ll cnta=sum,cntb=0;
    
    while(si(PQ)){
        auto u=PQ.top();PQ.pop();
        //cout<<u.fi<<" "<<u.se<<" "<<now<<" "<<ans<<" "<<cnta<<" "<<cntb<<endl;
        
        if(u.fi<=0){
            while(u.se){
                cnta--;
                cntb++;
                now+=u.fi;
                u.se--;
                if((cnta+S-1)/S+(cntb+S-1)/S<=need){
                    chmax(ans,now);
                    break;
                }
            }
            if((cnta+S-1)/S+(cntb+S-1)/S<=need){
                break;
            }
        }else if((cnta-u.se+S-1)/S+(cntb+u.se+S-1)/S<=need){
            now+=u.fi*u.se;
            cnta-=u.se;
            cntb+=u.se;
            
            chmax(ans,now);
        }else{
            ll move=max(0LL,(cntb+u.se)/S*S-cntb);
            now+=u.fi*move;
            cnta-=move;
            cntb+=move;
            
            if((cnta+S-1)/S+(cntb+S-1)/S<=need) chmax(ans,now);
            
            now-=u.fi*move;
            cnta+=move;
            cntb-=move;
            
            now+=u.fi*u.se;
            cnta-=u.se;
            cntb+=u.se;
        }
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}