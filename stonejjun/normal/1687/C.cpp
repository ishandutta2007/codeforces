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
ll pre[1010101];
ll chk[1010101];
ll brr[1010101];

ll uc[100][26];
ll fin[1000][26];
ll st=0;
ll en=80;

pii qr[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll i,j,k,a,b,c;
        cin>>n>>m;

        set<ll> s;
        for(i=0;i<=n;i++){
            s.insert(i);
            v[i].clear();

        }
        for(i=1;i<=n;i++)
            cin>>arr[i];
        for(i=1;i<=n;i++)
            cin>>brr[i];

        for(i=1;i<=n;i++){
            arr[i]-=brr[i];
            arr[i]+=arr[i-1];

        }

        for(i=1;i<=m;i++){
            chk[i]=0;
            cin>>qr[i].ff>>qr[i].ss;
            v[qr[i].ff-1].pb(i);
            v[qr[i].ss].pb(i);
        }

        queue<ll> q;
        for(i=0;i<=n;i++){
            if(arr[i]==0) q.push(i),s.erase(i);
        }

        while(q.size()){
            ll x=q.front();
            q.pop();
            for(auto k:v[x]){
                if(++chk[k]==2){
                    ll l=qr[k].ff;
                    ll r=qr[k].ss;
                    auto lt=s.lower_bound(l),rt=s.upper_bound(r);
                    for (auto it=lt;it!=rt;++it) q.push(*it);
                    s.erase(lt,rt);
                }
            }
        }


        if(s.size()==0){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';


        
    }
}