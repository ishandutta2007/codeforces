 #include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll a,b,x,y,u[MAX],r[MAX],le,ri,mid,ans,n,xx,yy;
string s;

int main(){
	cout<<fixed<<setprecision(5);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>x>>y>>n>>s;
    ans = -1;
    rep(i,1,n){
    	u[i] = u[i-1], r[i] = r[i-1];
    	if(s[i-1]=='U')u[i]++;
    	else if(s[i-1]=='D')u[i]--;
    	else if(s[i-1]=='R')r[i]++;
    	else if(s[i-1]=='L')r[i]--;
	}
	le = 0, ri = 1e18;
	while(le<=ri){
		mid = le+ri>>1;
		xx = r[n]*(mid/n) + r[mid%n], yy = u[n]*(mid/n) + u[mid%n];
		if(abs(x-a-xx)+abs(y-b-yy)<=mid)ans = mid, ri = mid-1;
		else le = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}