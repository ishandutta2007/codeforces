#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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

ll n,m,a[MAX],b[MAX],pa[MAX],pb[MAX],c[2*MAX],y[2*MAX],ans,cnt,le,ri,mid,nm,res;

void srt(int le,int ri,ll *x){
	if(le==ri)return;
	int mid = le+ri>>1;
	srt(le,mid,x), srt(mid+1,ri,x);
	int a = le, b = mid+1, id = le;
	while(a<=mid&&b<=ri){
		if(x[a]<x[b])y[id++] = x[a++];
		else y[id++] = x[b++];
	}
	while(a<=mid)y[id++] = x[a++];
	while(b<=ri)y[id++] = x[b++];
	rep(i,le,ri)x[i] = y[i];
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i], c[i] = a[i];
    rep(i,1,m)cin>>b[i], c[i+n] = b[i];
	nm = n+m;
    srt(1,n,a);
    srt(1,m,b);
	srt(1,nm,c);
	rep(i,1,n)pa[i] = pa[i-1]+a[i];
	rep(i,1,m)pb[i] = pb[i-1]+b[i];
	ans = 1e18;
	rep(k,1,nm){
		cnt = 0;
		le = 1, ri = n, res = 0;
		while(le<=ri){
			mid = le+ri>>1;
			if(a[mid]>=c[k])ri = mid-1;
			else le = mid+1, res = mid;
		}
		if(res)cnt+=c[k]*res-pa[res];
		le = 1, ri = m, res = 0;
		while(le<=ri){
			mid = le+ri>>1;
			if(b[mid]<=c[k])le = mid+1;
			else ri = mid-1, res = mid;
		}
		if(res)cnt+=(pb[m]-pb[res-1])-c[k]*(m-res+1);
		ans = min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}