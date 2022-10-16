#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=31623000;
const ll MAX2 = 1951971;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,k,cnt,prime[MAX2 + 5],sz,tot;
bool prima[MAX+5];
vector<ll> v;
vector<pll> fact;
void f(ll pos, ll pow, ll nw){
	if(pos>sz)return;
	if(pow>fact[pos].se){
		f(pos+1,1,nw);
		return;
	}
	f(pos+1,1,nw);
	v.pb(nw*fact[pos].fi); 
	f(pos,pow+1,nw*fact[pos].fi);
}
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,2,MAX){
    	if(prima[i])continue;
    	for(ll j=i*i;j<=MAX;j+=i)prima[j]=1;
	}
	rep(i,2,MAX)if(!prima[i])cnt++, prime[cnt]=i;
	cin>>n>>k;
	rep(i,1,MAX2){
		cnt=0;
		while(n%prime[i]==0){
			cnt++;
			n/=prime[i];
		}
		if(cnt)fact.pb(mp(prime[i],cnt));
	}
	if(n!=1)fact.pb(mp(n,1));
	v.pb(1);
	sz=fact.size(); sz--;
	f(0,1,1);
	sort(v.begin(),v.end());
	sz=v.size();
	//cout<<sz<<endl;
	if(k>sz)return cout<<-1, 0;
	cout<<v[k-1];
    return 0;
}