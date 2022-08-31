#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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

struct vec{
	double x,y;
	inline vec operator + (vec const &p)const{
		return (vec){x+p.x,y+p.y};
	}
	inline vec operator * (double const &p)const{
		return (vec){x*p,y*p};
	}
	inline double dis(){
		return sqrt(x*x+y*y);
	}
};

inline ll sqr(ll x){
	return x*x;
}
inline ll dis2(int a,int b,int c,int d){
	return sqr(a-c)+sqr(b-d);
}

int main(){
	int R=read(),x1=read(),y1=read(),x2=read(),y2=read();
	if (dis2(x1,y1,x2,y2)>=1ll*R*R) return printf("%d %d %d\n",x1,y1,R),0;
	if (x1==x2&&y1==y2) return printf("%0.12lf %0.12lf %0.12lf\n",x1+R/2.0,(double)y1,R/2.0),0;
	vec x=(vec){x1-x2,y1-y2};
	vec y=x*(1.0*R/x.dis());
	x=(x+y)*0.5;
	double ansx=x2+x.x,ansy=y2+x.y,ansr=x.dis();
	printf("%0.12lf %0.12lf %0.12lf\n",ansx,ansy,ansr);
}