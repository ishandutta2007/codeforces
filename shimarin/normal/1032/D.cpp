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

ll a,b,c,x1,y1,x2,y2;

#define Pa pair<double,double>
inline Pa calcx(int x,int y){
	return mp(x,(-1.0*a*x-c)/b);
}
inline Pa calcy(int x,int y){
	return mp((-1.0*b*y-c)/a,y);
}

inline double sqr(double x){
	return x*x;
}
inline double dis(Pa a,Pa b){
	return sqrt(sqr(a.fi-b.fi)+sqr(a.se-b.se));
}

int main(){
	a=read(),b=read(),c=read();
	x1=read(),y1=read(),x2=read(),y2=read();
	double ans=abs(x1-x2)+abs(y1-y2);
	Pa x=calcx(x1,y1),y=calcx(x2,y2);
	ans=min(ans,dis(mp(x1,y1),x)+dis(x,y)+dis(mp(x2,y2),y));
	x=calcx(x1,y1),y=calcy(x2,y2);
	ans=min(ans,dis(mp(x1,y1),x)+dis(x,y)+dis(mp(x2,y2),y));
	x=calcy(x1,y1),y=calcx(x2,y2);
	ans=min(ans,dis(mp(x1,y1),x)+dis(x,y)+dis(mp(x2,y2),y));
	x=calcy(x1,y1),y=calcy(x2,y2);
	ans=min(ans,dis(mp(x1,y1),x)+dis(x,y)+dis(mp(x2,y2),y));
	printf("%0.12lf\n",ans);
}