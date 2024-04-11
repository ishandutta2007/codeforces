#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

namespace Geometry{
	#define db double
	const db eps = 1e-10;
	struct point{
		ll x,y;
		inline point operator + (const point &p){return (point){x+p.x,y+p.y};}
		inline point operator - (const point &p){return (point){x-p.x,y-p.y};}
		inline db operator * (const point &p){return x*p.x+y*p.y;}
	};
	typedef point vec;
	inline ll cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
	struct line{
		point a,b;
	};
	inline int checkseg(line a,line b){
		point A=a.a,B=a.b,C=b.a,D=b.b;
		if (max(A.x,B.x)<min(C.x,D.x)) return 0;
		if (min(A.x,B.x)>max(C.x,D.x)) return 0;
		if (max(A.y,B.y)<min(C.y,D.y)) return 0;
		if (min(A.y,B.y)>max(C.y,D.y)) return 0;
		ll s=cross(B-A,C-A),h=cross(B-A,D-A);
		if ((__int128)s*h>=1) return 0;
		ll i=cross(D-C,A-C),t=cross(D-C,B-C);
		return (__int128)i*t<=0;
	}
	const int inf = 1e9;
	inline PA cross_point(line a,line b){
		point A=a.a,B=a.b,C=b.a,D=b.b;
		ll s1=fabs(cross(B-A,C-A)),s2=fabs(cross(B-A,D-A));
		PA CO=mp(D.x-C.x,D.y-C.y);
		if ((__int128)CO.fi*s1%(s1+s2)) return mp(-inf,-inf);
		if ((__int128)CO.se*s1%(s1+s2)) return mp(-inf,-inf);
		CO.fi=(__int128)CO.fi*s1/(s1+s2);
		CO.se=(__int128)CO.se*s1/(s1+s2);
		return mp(C.x+CO.fi,C.y+CO.se);
	}
};
using namespace Geometry;

line l[1100];

int main(){
	int n=read();
	ll ans=0;
	For(i,1,n){
		ll a=read(),b=read(),c=read(),d=read();
		l[i].a.x=a,l[i].a.y=b;
		l[i].b.x=c,l[i].b.y=d;
		ll x=abs(c-a),y=abs(d-b);
		if (x==0&&y==0) ++ans;
		else if (x==0) ans+=y+1;
		else if (y==0) ans+=x+1;
		else ans+=__gcd(x,y)+1;
	}
	For(i,1,n){
		map<PA,int>f;
		For(j,i+1,n){
			if (checkseg(l[i],l[j])){
				PA c=cross_point(l[i],l[j]);
				if (c.fi==-inf&&c.se==-inf) continue;
				ll X=(ll)c.fi,Y=(ll)c.se;
				if (f[mp(X,Y)]) ++ans;
				--ans,f[mp(X,Y)]=1;
			}
		}
	}
	printf("%lld\n",ans);
}