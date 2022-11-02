#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss secondac
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
ll chk[1010101];

vector<ll> v[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>n;
    ll chkk=0;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        arr[0]=arr[1];
        if(arr[i-1]!=arr[i]) chkk=1;
    }

    if(chkk==0){
        cout<<0;
        return 0;
    }

    while(1){
        ll mb=0;
        for(i=0;i<=30;i++){
            for(j=1;j<=n;j++){
                if(arr[j]&(1LL<<i))
                    mb=max(mb,i);
            }
        }
        //cout<<mb<<'\n';
        ll fl=0;
        for(i=1;i<=n;i++){
            chk[i]=0;
            if(arr[i]&(1LL<<mb)){
                chk[i]=1;
            }
            else fl=1;
        }

        if(fl) break;
        for(i=1;i<=n;i++){
            arr[i]-=(1LL<<mb);
        }
    } 
    ll ans=0;
    chk[0]=chk[n+1]=1;

//    for(i=1;i<=n;i++){
//        cout<<i<<' '<<chk[i]<<'\n';
 //   }

    for(i=1;i<=n;i++){
        if(chk[i]==1){
            ll fl;
            fl=i;
            ll vmax=0;
            while(chk[fl-1]==0){
                fl--;
                vmax=max(vmax,arr[fl]);
                ans=max(ans,arr[i]^vmax);
            }

            fl=i;
            vmax=0;
            while(chk[fl+1]==0){
                fl++;
                vmax=max(vmax,arr[fl]);
                ans=max(ans,arr[i]^vmax);
            }

        }
    }

    cout<<ans;
}