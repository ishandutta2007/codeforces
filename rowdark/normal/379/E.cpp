#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T Mul(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Pow(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=Mul(F1,x,P);
		}
		x=Mul(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdateMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

#define MaxBuffer 20000000
class ReadBuffer{
	private:
	char buff[MaxBuffer];
	char *buf;
	public:
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
		buf=buff;
	}
	template<class T>
	bool readInteger(T &x)
	{
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag;
		flag=0;
		if(*buf=='-') flag=true;
		else x=*buf-'0';
		while(isdigit(*++buf)) x=x*10+*buf-'0';
		if(flag) x=-x;
		return true;
	}
	template<class T>
	bool readFloat(T &x)
	{
		long double nowpos=0.1;
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag,decimal;
		decimal=flag=0;
		if(*buf=='-') flag=true,++buf;
		else if(*buf=='.') decimal=true;
		while(isdigit(*buf)||*buf=='.')
		{
			if(*buf=='.') decimal=true;
			else
			{
				if(decimal)
				{
					x+=nowpos*(*buf-'0');
					nowpos*=0.1;
				}
				else
				{
					x=x*10+*buf-'0';
				}
			}
			++buf;
		}
		return true;
	}
	bool readChar(char c)
	{
		if(*buf==0) return 0;
		return c=*buf++,1;
	}
	bool readString(char *s)
	{
		while(*buf&&isspace(*buf)) ++buf;
		if(!*buf) return false;
		while(!isspace(*buf)) *s++=*buf++;
		*s++=0;
		return true;
	}
	int countSpacetonext(){
		int total=0;
		while(*buf&&*buf==' ') ++total,++buf;
		return total;
	}
	bool splitBycharactor(char *s,char Split='\n'){
		while(*buf&&*buf!=Split) *s++=*buf++;
		*s++=0;
		return *buf!=0;
	}
};

struct EDGE{
	int T;EDGE *Nxt;
};
const double eps=1e-6;
inline int Sign(double a) {
    return a < -eps ? -1 : a > eps;
}
struct Point {
    double x, y;
    Point() {
    }
    Point(double x, double y) : x(x), y(y) {
    }
    void Input() {
        scanf("%lf %lf", &x, &y);
    }
	bool operator <(const Point &p)const{return Sign(x-p.x)<0||Sign(x-p.x)==0&&Sign(y-p.y)<0;}
	Point operator +(const Point &p)const{return Point(x+p.x,y+p.y);}
	Point operator -(const Point &p)const{return Point(x-p.x,y-p.y);}
	Point operator *(const double &p)const{return Point(x*p,y*p);}
	Point operator /(const double &p)const{return Point(x/p,y/p);}
	bool operator ==(const Point &p)const{return Sign(x-p.x)==0&&Sign(y-p.y)==0;}
};
inline double Det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
inline double Dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
inline bool In_The_Seg(const Point &a, const Point &b, const Point &c) {
    return Sign(Dot(a - c, b - c)) <= 0;
}

inline bool Seg_Intersect(const Point &a, const Point &b, const Point &c, const Point &d, Point &e) {
    double s1 = Det(c - a, d - a);
    double s2 = Det(d - b, c - b);
    if (!Sign(s1 + s2)) return 0;
    e = (b - a) * (s1 / (s1 + s2)) + a;
    return In_The_Seg(a, b, e) && In_The_Seg(c, d, e);
}
vector<Point> S,NS;
int maxv[301];
double ans;
int n,k;
int y[301];
Point now[301];
inline Point getpoint(const Point &a,const Point &b,double x){
	return Point(x,((x-a.x)*b.y+(b.x-x)*a.y)/(b.x-a.x));
}
inline double calc(const Point &c,const Point &d,const Point &a,const Point &b){
	if(Sign(a.y-c.y)>=0&&Sign(b.y-d.y)>=0){
		return (a.y-c.y+b.y-d.y)/2*(b.x-a.x);
	}
	else return 0.0;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;++i) S.PB(Point(i*1.0,0.0));
	for(int i=1;i<=n;++i){
		for(int j=0;j<=k;++j){
			scanf("%d",y+j);
			now[j]=Point(j,y[j]);
		}
		int iter=0;
		NS.clear();
		double ans=0;
		for(int i=0;i<k;++i){
			while(Sign(S[iter].x-(i+1))<0){
				Point ps=getpoint(now[i],now[i+1],S[iter].x);
				Point x=S[iter];
				++iter;
				Point y=S[iter];
				Point pt=getpoint(now[i],now[i+1],S[iter].x);
				Point z;
				if(Seg_Intersect(ps,pt,x,y,z)){
					ans+=calc(x,z,ps,z);
					if(ps.y>=x.y) NS.push_back(ps);
					else NS.push_back(x);
					NS.push_back(z);
					ans+=calc(z,y,z,pt);
					if(y.y>=pt.y) NS.push_back(y);
					else NS.push_back(pt);
				}
				else
				{
					if(ps.y>=x.y) NS.push_back(ps);
					else NS.push_back(x);
					ans+=calc(x,y,ps,pt);
					if(y.y>=pt.y) NS.push_back(y);
					else NS.push_back(pt);
				}
			}
		}
		printf("%.10f\n",ans);
		NS.resize(unique(NS.begin(),NS.end())-NS.begin());
		swap(NS,S);
	}
	return 0;
}