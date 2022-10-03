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
const int mod=998244353,MAX=400005,INF=1000000000;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int wa[MAX];

vector<ll> ngg[MAX],okk[MAX];
vector<int> mae[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int t=2;t<MAX;t*=2){
        for(int i=t;i<MAX;i+=t){
            wa[i]++;
        }
    }
    
    for(int i=1;i<=200000;i++){
        for(int c=2*i;c<=200000;c+=i){
            mae[c].push_back(i);
        }
    }
    
    for(ll i=1;i<=400000;i++){
        for(ll c=i;c<=400000;c+=i){
            if(c&1) continue;
            if(i>=c/2) continue;
            if(wa[i]==wa[c]) okk[c/2].push_back(i);
            else ngg[c/2].push_back(i);
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        ll l,r;cin>>l>>r;
        ll ans=0;
        for(ll c=l+2;c<=r;c++){
            ll cn=0;
            for(int x:mae[c]) if(l<=x&&x<r) cn++;
            ans+=cn*(cn-1)/2;
        }
        //cout<<ans<<endl;
        for(ll c=l+2;c<=r;c++){
            vector<ll> ng,ok;
            for(ll a:ngg[c]){
                if(a>=l) ng.push_back(a);
            }
            for(ll a:okk[c]){
                if(a>=l) ok.push_back(a);
            }
            
            vector<ll> ok2=ok;
            auto it1=ng.begin(),it2=ok2.begin();
            
            reverse(all(ok));
            int t=0;
            for(ll x:ok){
                ll need=2*c+1-c-x;
                while(it1!=ng.end()&&(*it1)<need) it1++;
                ans+=(ng.end()-it1);
                
                while(it2!=ok2.end()&&(*it2)<need) it2++;
                if(need<=x+1){
                    ans+=t;
                }else{
                    ans+=(ok2.end()-it2);
                }
                t++;
            }
        }
        ll n=(r-l+1);
        ans=n*(n-1)*(n-2)/6-ans;
        cout<<ans<<"\n";
    }
}