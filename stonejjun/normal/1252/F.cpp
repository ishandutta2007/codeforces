#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
ll mod=998244353;
ll arr[210101][44];

ll n,m;
string s[202020];
vector<ll> v[202020];
vector<ll> rev[202020];
ll dis[20][202020];
pii dis2[202020];
ll inf=1e9;
ll inv[10101010];
ll anbit[101010];


int main(){
    mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t,T;

    ll i,j,k,l;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;
    ll ans=0;
    cin>>n>>m>>k;

    for(i=1;i<=n;i++)
        cin>>s[i];

    uniform_int_distribution<ll> rnd(1, n);
    for(ll z=1;z<=30;z++){

        vector<ll> cho;
        vector<ll> vals;
        ll p=rnd(rd);
      //  ll p=1;
       // cout<<z<<' '<<p<<' '<<ans<<'\n';

        for(j=0;j<m;j++){
            if(s[p][j]=='1') cho.pb(j);
        }

        //cout<<z<<' '<<p<<' '<<ans<<'\n';
        k=cho.size();
       /* for(j=0;j<k;j++)
            for(i=1;i<=n;i++)
                arr[i][j]=s[i][cho[j]]-'0';
*/
        ll pval=0;
        for(i=1;i<=n;i++){
            ll val=0;
            for(j=0;j<k;j++){
                if(s[i][cho[j]]-'0'==0){
                    val+=(1<<j);
                }
            }
            vals.pb(val);
        }

        //cout<<z<<' '<<p<<' '<<ans<<'\n';
        for(auto k:vals){
  //          cout<<z<<' '<<p<<' '<<k<<'\n';
            inv[k]++;
        }

        //cout<<z<<' '<<p<<' '<<ans<<'\n';
        for(ll msk=0;msk<(1<<k);msk++){
            ll ccnt=inv[0];
            //cout<<"qwerqwe"<<msk<<'\n';
            //cout<<ccnt<<'\n';
            for (j = msk;j;j = (j-1)&msk){
                ccnt+=inv[j];
            //    cout<<j<<' '<<ccnt<<'\n';
            }
            if(ccnt>=(n+1)/2){
                if(ans<k-__builtin_popcount(msk)){
                    ans=k-__builtin_popcount(msk);
              //      cout<<ans<<' '<<msk<<'\n';
                //    cout<<p<<' '<<k<<'\n';
                    for(i=0;i<m;i++)
                        anbit[i]=0;
                    for(i=0;i<k;i++){
                        if(((1LL<<i)&msk)==0){
                  //          cout<<i<<'\n';
                    //        cout<<cho[i]<<'\n';
                            anbit[cho[i]]=1;
                        }
                    }
                }
            }
        }

        for(auto k:vals){
            inv[k]--;
        }

    }
//    cout<<ans<<'\n';

    for(i=0;i<m;i++)
        cout<<anbit[i];
        
}