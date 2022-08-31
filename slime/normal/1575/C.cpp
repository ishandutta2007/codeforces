#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 1234567
struct comp {ld a,b;
comp() {}
comp(ld x):a(x),b(0) {}
comp(ld x,ld y):a(x),b(y) {}
}; //a+bi
inline comp operator + (comp a,comp b)
{return comp(a.a+b.a,a.b+b.b);}
inline comp operator - (comp a,comp b)
{return comp(a.a-b.a,a.b-b.b);}
inline comp operator * (comp a,comp b)
{return comp(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);}
ostream& operator << (ostream& a,comp b)
{a<<"("<<b.a<<","<<b.b<<")"; return a;}
int K; comp w[2][SZ];
comp qp(comp a,ll b)
{
	comp x=1;
	while(b)
	{
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
ll qp(ll a,ll b,int MOD)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
const ld pi=acos(-1);
int rev[SZ];
void init(int s)
{
	for(K=1;K<s;K<<=1);
	{
	ld t=pi*2/K;
	for(int i=0;i<=K;++i)
		w[0][i]=comp(cos(t*i),sin(t*i));
	}
	for(int i=0;i<=K;++i)
		w[1][i]=w[0][K-i];
	for(int i=0;i<K;++i)
	{
		int t=0,x=i;
		for(int j=1;j<K;j<<=1)
			t=t*2+(x&1),x>>=1;
		rev[i]=t;
	}
}
void fft(comp*x,int k)
{
	for(int i=0;i<K;++i)
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int i=2;i<=K;i<<=1)
		for(int j=0;j<K;j+=i)
			for(int s=0;s<(i>>1);++s)
			{
				comp t=x[j+s+(i>>1)]*w[k][K/i*s];
				x[j+s+(i>>1)]=x[j+s]-t;x[j+s]=x[j+s]+t;
			}
	if(k) return;
	//better precision!
	ld sK=sqrt(K);
	for(int i=0;i<K;++i)
		x[i].a/=sK, x[i].b/=sK;
}
int a0_[SZ],b0_[SZ],a1_[SZ],b1_[SZ]; ll x0_[SZ],x1_[SZ];
comp a0[SZ],b0[SZ],a1[SZ],b1[SZ],x0[SZ],x1[SZ],x2[SZ];
comp ps[SZ];
template<class T>
void comb_fft0(T*a,T*b,comp*aa,comp*bb)
{
	for(int i=0;i<K;++i)
		ps[i].a=a[i],ps[i].b=b[i];
	fft(ps,0);
	for(int i=0;i<K;++i)
	{
		comp pr=ps[i?(K-i):i];
		pr.b=-pr.b;
		aa[i]=(ps[i]+pr)*0.5;
		bb[i]=(ps[i]-pr)*0.5;
		swap(bb[i].a,bb[i].b);
		bb[i].b=-bb[i].b;
	}
}
template<class T>
void comb_fft1(comp*aa,comp*bb,T*a,T*b)
{
	for(int i=0;i<K;++i)
	{
		comp t=bb[i]; t.b*=-1;
		swap(t.a,t.b); ps[i]=aa[i]+t;
	}
	fft(ps,1);
	for(int i=0;i<K;++i)
		a[i]=llround(ps[i].a),
		b[i]=llround(ps[i].b);
}
#define B 32768
vector<int> conv(const vector<int>& a,const vector<int>& b,int p)
{
	if(a.size()&&b.size());else return vector<int>();
	init(a.size()+b.size()+2);
	for(int i=0;i<K;++i) a0_[i]=a1_[i]=b0_[i]=b1_[i]=0;
	for(int i=0;i<(int)a.size();++i)
	{
		int t=(a[i]%p+p)%p;
		a0_[i]=t%B,a1_[i]=t/B;
	}
	for(int i=0;i<(int)b.size();++i)
	{
		int t=(b[i]%p+p)%p;
		b0_[i]=t%B,b1_[i]=t/B;
	}
	comb_fft0(a0_,a1_,a0,a1);
	comb_fft0(b0_,b1_,b0,b1);
	for(int i=0;i<K;++i)
		x0[i]=a0[i]*b0[i],
		x1[i]=a0[i]*b1[i]+a1[i]*b0[i],
		x2[i]=a1[i]*b1[i];
	comb_fft1(x0,x1,x0_,x1_); fft(x2,1);
	vector<int> c;
	for(int i=0;i<int(a.size()+b.size()-1);++i)
	{
		ll s=x0_[i]%p+x1_[i]%p*B
		+llround(x2[i].a)%p*B%p*B;
		s=(s%p+p)%p; c.pb(s);
	}
	return c;
}
#undef B
int n,m,k,a[SZ],s[SZ];
ll su=0;
const int MOD=1e9+7;
int cm[SZ];
ll calc_z(int p) {
	memset(cm,0,sizeof cm);
	ll aa=0;
	for(int i=0;i<=n;++i) {
		aa+=cm[(s[i]-p+k)%k];
		cm[s[i]]++;
//		cout<<i<<":"<<aa<<"??\n";
	}
	aa%=MOD;
	aa=aa*m%MOD;
//	cout<<aa<<"??\n";
	vector<int> ss(k+1),sb(k+1);
	for(int i=1;i<=n;++i)
		ss[s[i]]++;
	for(int i=0;i<n;++i)
		sb[(s[n]-s[i]+k)%k]++;
	ss=conv(ss,sb,MOD);
	vector<int> oo(k+1);
	for(int i=0;i<ss.size();++i)
		(oo[i%k]+=ss[i])%=MOD;
	for(int u=2;u<=m;++u) {
		aa+=oo[((p-s[n]*(ll)(u-2))%k+k)%k]*(ll)(m-u+1)%MOD;
	}
//	cout<<p<<":"<<aa<<"\n";
	return aa;
}
ll calc_pre(int su) {
	vector<int> ss(k+1);
	for(int i=1;i<=n;++i) {
		ss[s[i]]++;
	}
	ll aa=0;
	for(int u=0;u<m;++u) {
		aa+=ss[((su-s[n]*(ll)u)%k+k)%k];
		aa%=MOD;
	}
//	cout<<aa<<"p??\n";
	return aa%MOD;
}
ll calc_suf(int su) {
	vector<int> ss(k+1);
	for(int i=0;i<n;++i) {
		ss[(s[n]-s[i]+k)%k]++;
	}
	ll aa=0;
	for(int u=0;u<m;++u) {
		aa+=ss[((su-s[n]*(ll)u)%k+k)%k];
		aa%=MOD;
	}
//	cout<<aa<<" "<<s[n]<<","<<su<<"s??\n";
	return aa%MOD;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
		s[i]=(s[i-1]+a[i])%k;
	su=s[n]*(ll)m%k;
	ll ans=calc_z(0);
//	cout<<ans<<"?\n";
	ans+=calc_z(su)-calc_pre(su)-calc_suf(su)+1;
	ans%=MOD; ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}