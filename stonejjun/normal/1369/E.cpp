#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
ll arr[1010101];
ll fchk[1010101];
ll pchk[1010101];
ll sarr[1010101];
ll brr[1010101];
ll w[101010];

ll n,m;
string s;
ll ans[1010101];
ll dp[2020][2020];
vector<ll> v[202020];
ll cnt[1010101];
ll inf=1e18;
ll mval;
queue<ll> q;
stack<ll> sans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    ll i,j,k,l;
//    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;
    string s2;
    ll cchk=0;

    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>w[i];
    for(i=1;i<=m;i++){
        cin>>arr[i]>>brr[i];
        sarr[arr[i]]++;
        sarr[brr[i]]++;
        v[arr[i]].pb(i);
        v[brr[i]].pb(i);
    }

    for(i=1;i<=n;i++){
        if(w[i]>=sarr[i]){
            fchk[i]=1;
            q.push(i);
        }
    }

    while(q.size()){
        auto p=q.front(); q.pop();
      //  cout<<p<<'\n';
        for(auto k:v[p]){
            if(pchk[k]==0){
              //  cout<<p<<' '<<k<<'\n';

                pchk[k]=1;
                sans.push(k);
                sarr[arr[k]]--;
               // cout<<arr[k]<<' '<<sarr[arr[k]]<<' '<<w[arr[k]]<<'\n';
                if(sarr[arr[k]]==w[arr[k]]){
                    q.push(arr[k]);
                }
                sarr[brr[k]]--;
               // cout<<brr[k]<<' '<<sarr[brr[k]]<<' '<<w[brr[k]]<<'\n';
                if(sarr[brr[k]]==w[brr[k]]){
                    q.push(brr[k]);
                }
            }
        }
    }

    if(sans.size()!=m){
        cout<<"DEAD";
    }
    else{
        cout<<"ALIVE"<<'\n';
        while(sans.size()){
            cout<<sans.top()<<' ';
            sans.pop();
        }
    }

}