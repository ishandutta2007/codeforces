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
string s;
ll mod=998244353;
ll arr[1010101];
ll pre[1010101];
ll suf[1010101];
vector<ll> v[1010101];
ll chk[1010101];
ll tree[1010101];

void upt(ll idx,ll val,ll s,ll e,ll nod){
	if(idx<s||e<idx) return ;
	if(s==e){
		tree[nod]=val;
		return ;
	}
	ll m=(s+e)/2;
	upt(idx,val,s,m,nod*2);
	upt(idx,val,m+1,e,nod*2+1);
	tree[nod]=max(tree[nod*2],tree[nod*2+1]);
}

ll sol(ll l,ll r,ll s,ll e,ll nod){
	///bcout<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<nod<<' '<<tree[nod]<<'\n';
	if(r<s||e<l) return 0;
	if(l<=s&&e<=r){
		return tree[nod];
	}
	ll m=(s+e)/2;
	return max(sol(l,r,s,m,nod*2),sol(l,r,m+1,e,nod*2+1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   		ll i,j,k,a=0,b=0,c=0,d,e,f;
   		cin>>m>>n;
   		for(i=1;i<=n;i++){
   			cin>>arr[i];
   			upt(i,arr[i],1,n,1);
   		}
   		cin>>k;
   		while(k--){
   			cin>>a>>b>>c>>d>>e;
   			if((abs(b-d)%e)!=0||(abs(a-c)%e)!=0){
   				cout<<"NO"<<'\n';
   				continue;
   			}
   			else{
   				ll f=(m-a)/e;
   				ll x=a+f*e;
   				ll y=sol(min(b,d),max(b,d),1,n,1);
   				//cout<<k<<' '<<x<<' '<<y<<'\n';
   				if(y>=x){
   					cout<<"NO"<<'\n';
   				}
   				else cout<<"YES"<<'\n';
   			}
   		}
   	
}