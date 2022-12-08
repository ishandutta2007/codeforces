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
double p[2005],ans;
double  calc1(int P){
	ld l=1.0;
	double ans=0,sum=0;
	for(int i=1;i<=P;i++) l/=e;
	int si=0;
	for(int i=0;i<=P*2;i++){
		ans+=sqr(l-(double)cnt[i]/250.0);
		l=l*P/(i+1);
		if(ans>::ans) return ans;
	}
	if(si>1) return inf;
	return ans;
}
double  calc2(int P){
	for(int i=1;i<=250;i++)
		if(a[i]>P*2) return inf;
	double  ans=0.0;
	for(int i=0;i<=P*2;i++){
		ans+=sqr(1.0/P/2-(double)cnt[i]/250.0);
		if(ans>::ans) return ans;
	}
	return ans;
}
double b[2005],c[2005];
struct node{double x;int y;}d[2005];
bool cmp(node a,node b){return a.x<b.x;}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	while(T--){
	ans=inf;
		int res=0;
		clr(cnt,0);
		for(int i=1;i<=250;i++)
			scanf("%d",&a[i]),cnt[a[i]]++;
		for(int P=10;P<=1000;P++){
			b[P]=calc1(P);c[P]=calc2(P);
			if(b[P]<ans) ans=b[P],res=P;
			if(c[P]<ans) ans=c[P],res=P;
		}
		printf("%d\n",res);
	}
	return 0;
}