#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
const double inf=1e9,e=2.718281828459;
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=305,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int a[N],cnt[2005];
double  p[2005];
double  calc1(int P){
	int m=0;
	clr(cnt,0);
	for(int i=1;i<=250;i++){
		if(a[i]>P*2) return inf/2;
		gmax(m,a[i]),cnt[a[i]]++;
	}
	double l=e,r=1,ans=0,sum=0;
	clr(p,0);
	for(int i=6*P/10;i<=14*P/10;i++)
		p[i]=(double )(abs(i-P)+P-7*P/10),sum+=p[i];
	for(int i=6*P/10;i<=14*P/10;i++)
		p[i]/=sum;
	int si=0;
	for(int i=0;i<=P*2;i++){
		if(p[i]<1e-9&&cnt[i]) si++;
		ans+=sqr(p[i]-(double)cnt[i]/250.0);
	}
	if(si>10) return inf;
//	debug(P);
	return ans;
}
double  calc2(int P){
	clr(cnt,0);
	for(int i=1;i<=250;i++)
		if(a[i]>P*2) return inf; else cnt[a[i]]++;
	double  ans=0.0;
	for(int i=0;i<=P*2;i++)
		ans+=sqr(1.0/2.0/P-(double)cnt[i]/250.0);
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	while(T--){
		double  a1=inf/2,a2=inf;
		for(int i=1;i<=250;i++)
			scanf("%d",&a[i]);
		for(int P=10;P<=1000;P++){
			gmin(a1,calc1(P));
			gmin(a2,calc2(P));
		}
		if(a1<a2) puts("poisson"); else puts("uniform");
	}
	return 0;
}