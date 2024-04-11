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
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> S(N);
    for(int i=0;i<N;i++) cin>>S[i].fi;
    for(int i=0;i<N;i++) cin>>S[i].se;
    sort(all(S),[](auto a,auto b){
        //return a.fi/a.se>b.fi/b.se;
        if(a.fi*b.se==b.fi*a.se) return a.fi<b.fi;
        return a.fi*b.se>b.fi*a.se;
    });
    
    //for(auto a:S) cout<<a.fi<<" "<<a.se<<endl;
    
    map<ll,ll> mi,ma;
    
    int i=0;
    ll tsum=0;
    while(i<N){
        int j=i;
        ll l=tsum,r=tsum;
        while(j<N&&S[i].fi*S[j].se==S[j].fi*S[i].se){
            r+=S[j].se;
            j++;
        }
        for(int k=i;k<j;k++){
            ll p=S[k].fi,x=S[k].se;
            if(mi.count(p)){
                chmin(mi[p],-(l+x)*p);
                chmin(mi[p],-r*p);
            }else{
                mi[p]=-(l+x)*p;
                chmin(mi[p],-r*p);
            }
            if(ma.count(p)){
                chmax(ma[p],-(l+x)*p);
                chmax(ma[p],-r*p);
            }else{
                ma[p]=-(l+x)*p;
                chmax(ma[p],-r*p);
            }
        }
        
        for(int k=i;k<j;k++) tsum+=S[k].se;
        
        i=j;
    }
    
    vector<ll> use;
    for(auto a:mi) use.push_back(a.fi);
    
    double ans=1.0;
    
    for(int i=0;i+1<si(use);i++){
        double a=(double)(ma[use[i]])/tsum;
        double b=(double)(mi[use[i+1]])/tsum;
        if(ma[use[i]]>mi[use[i+1]]){
            chmin(ans,(double)(use[i+1]-use[i])/(a-b));
        }
    }
    
    i=0;
    ll T=tsum;
    tsum=0;
    while(i<N){
        int j=i;
        ll l=tsum,r=tsum;
        while(j<N&&S[i].fi*S[j].se==S[j].fi*S[i].se){
            r+=S[j].se;
            j++;
        }
        for(int k=i;k+1<j;k++){
            if(S[k].fi==S[k+1].fi) continue;
            double a=(double)-S[k].fi*(l+S[k].se)/T;
            double b=(double)-S[k+1].fi*r/T;
            chmin(ans,(double)(S[k+1].fi-S[k].fi)/(a-b));
        }
        
        for(int k=i;k<j;k++) tsum+=S[k].se;
        
        i=j;
    }
    
    cout<<fixed<<setprecision(25)<<ans<<endl;
    
}