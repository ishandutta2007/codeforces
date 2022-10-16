#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=998244353;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll n,x[505],a,b,ans,tmp;
bool vis[505];
map<ll,ll> m,s;

ll sqr3(ll cek){
	ll le = 1, ri = 1260000, mid;
	while(le<=ri){
		mid = (le+ri)/2;
		if(mid*mid*mid==cek)return mid;
		if(mid*mid*mid<cek)le = mid+1;
		else ri = mid-1;
	}
	return 0;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	a = sqrt(x[i]);
    	if(a*a==x[i]){
    		vis[i] = 1;
    		b = sqrt(a);
    		if(b*b==a)m[b]+=4;
			else m[a]+=2;
		}
		else if(sqr3(x[i])){
			vis[i] = 1;
			m[sqr3(x[i])]+=3;
		}
	}
	rep(i,1,n){
		if(vis[i])continue;
		rep(j,1,n){
			if(x[i]==x[j])continue;
			tmp = __gcd(x[i],x[j]);
			if(tmp==1)continue;
			m[tmp]++;
			m[x[i]/tmp]++;
			vis[i] = 1;
			break;
		}
		if(!vis[i])s[x[i]]++;
	}
	ans = 1;
	for(auto i:m)ans = (ans*(i.se+1))%MOD;
	for(auto i:s)ans = (ans*(i.se+1)*(i.se+1))%MOD;
	cout<<ans<<endl;
    return 0;
}