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
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

const double inf=2e10,eps=1e-6;
int n,p,a[N],b[N];

int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	double l=0,r=inf*10;
	while(l+eps<r){
		double mid=(l+r)/2.0,use=0.0;
		for(int i=1;i<=n;i++)
			use+=max((double)0.0,(double)a[i]*mid-(double)b[i]);
		if(use/p>mid-eps) r=mid; else l=mid;
	}
	if(r<inf) printf("%.6f\n",r); else puts("-1");
	return 0;
}