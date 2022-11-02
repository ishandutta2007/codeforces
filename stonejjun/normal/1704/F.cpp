#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
string t;
ll arr[1010101];
vector<ll> v[1010101];
ll ans[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i,j,k,a,b,c,d,e,f;
    ans[1]=ans[2]=1;
    for(i=3;i<=110;i++){
        //cout<<i<<'\n';
        x.clear();
        x.pb(ans[i-2]);
        for(j=0;j<=i-3;j++){
            x.pb(ans[j]^ans[i-j-3]);
        }
        compress(x);
        x.pb(10000000);
        for(j=0;j<x.size();j++){
            //cout<<i<<' '<<j<<' '<<x[j]<<'\n';
            if(x[j]!=j) {
                ans[i]=j;
                break;
            }
        }
    }


    ll tt;
    cin>>tt;
    while(tt--){
        x.clear();
    	ll i,j,k,l,a=0,b=0,c;
    	cin>>n;
    	cin>>s;

        for(i=0;i<=2*n+3;i++)
            arr[i]=0;

        for(i=1;i<=n;i++){
            if(s[i-1]=='R') a++;
            else b++;
        }

        if(a>b){
            cout<<"Alice"<<'\n';
        }
        else if(b>a){
            cout<<"Bob"<<'\n';
        }
        else{
            ll cnt=0;
            for(i=1;i<n;i++){
                if(s[i]!=s[i-1]){
                    cnt++;
                    arr[i]=1;
                }
                else{
                    x.pb(cnt);
                    cnt=0;
                }
            }
            x.pb(cnt);

            ll fl=0;
            for(auto k:x){
                if(k>=100){
                    k=k%34;
                    k+=68;
                }
                fl^=ans[k];
            }

            if(fl){
                cout<<"Alice"<<'\n';
            }
            else{
                cout<<"Bob"<<'\n';
            }
        }
    }
}