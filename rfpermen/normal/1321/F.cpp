#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,q,pf[MAX],le[MAX],ri[MAX],l[MAX],r[MAX],cl[MAX],jlh[MAX],cnt,a,b,len,id,ls;
ll hs[MAX],x[MAX],key,tmp,pj,t2;
bool z[MAX],st;
char c;
pair<ll,int> res;

inline pair<ll,int> f(int a,int b){
	if(a>b)return {0,0};
	int len = b-a+1;
	return {x[b]-x[a-1]*hs[len],len};
}

inline pair<ll,int> comp(int a,int b){
	tmp = pj = st = 0;
	if(z[a]){
		if(ri[a]-a+1&1)++pj;
		a = ri[a]+1;
	}
	if(z[b]){
		if(b-le[b]+1&1)st = 1;
		b = le[b]-1;
	}
	if(cl[a]==cl[b]){
		tmp = l[a]+r[b]-jlh[cl[a]];
		if(st)tmp*= key;
		return {tmp,1+pj+st};
	}
	res = f(cl[a]+1,cl[b]-1);
	tmp = (l[a]*hs[res.se] + res.fi)*key + r[b];
	if(st)tmp*= key;
	return {tmp,cl[b]-cl[a]+1+pj+st};
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    key = 2000003153;
    cin>>n;
    hs[0] = 1;
    rep(i,1,n){
    	cin>>c, z[i] = (c=='1'), pf[i] = pf[i-1]+z[i], hs[i] = hs[i-1]*key;
    	if(z[i]){
    		st^=1;
    		if(le[i-1])le[i] = le[i-1];
    		else le[i] = i;
		}
		else {
			if(st){
				jlh[id] = cnt;
				x[id] = x[id-1]*key + cnt;
				st = cnt = 0;
			}
			if(cnt==0)++id;
			++cnt, r[i] = cnt;
			cl[i] = id;
		}
	}
	if(cnt)x[id] = x[id-1]*key + cnt, jlh[id] = cnt;
	ls = id;
	cnt = 0;
	rap(i,n,1){
		if(z[i]){
			if(ri[i+1])ri[i] = ri[i+1];
			else ri[i] = i;
		}
		else {
			if(cl[i]!=ls)cnt = 0, ls = cl[i];
			l[i] = ++cnt;
		}
	}
    cin>>q;
    while(q--){
    	cin>>a>>b>>len;
//    	rep(i,a,a+len-1)cout<<z[i]; cout<<endl;
//    	rep(i,b,b+len-1)cout<<z[i]; cout<<endl;
    	if(pf[a+len-1]-pf[a-1]!=pf[b+len-1]-pf[b-1]){
    		cout<<"No\n"; continue;
		}
		if(pf[a+len-1]-pf[a-1]==0||pf[a+len-1]-pf[a-1]==len){
			cout<<"Yes\n"; continue;
		}
		if(comp(a,a+len-1)==comp(b,b+len-1))cout<<"Yes\n";
		else cout<<"No\n";
	}
    return 0;
}