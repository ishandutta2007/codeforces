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
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=500005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,a[N],s[N],l[N],r[N];

ll get(int x,int y){
	if(x+1==y) return 0;
	ll ans=min(a[x],a[y]);
	for(int i=x+1;i<y;i++){
		if(a[i-1]<a[i]) ans+=a[i];
		if(a[i+1]<=a[i]) ans+=a[i];
	}
	return ans;
}

ll solve(int x,int y){
	if(x==y-1) return 0;
	if(a[x]<=a[y]){
		if(r[x]==y) return get(x,y);
		return min(a[x],a[y])+get(x,r[x])+solve(r[x],y);
	}
	else if(l[y]==x) return get(x,y);
	return min(a[x],a[y])+get(l[y],y)+solve(x,l[y]);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	if(n==1){puts("0");return 0;}
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1,top=0;i<=n;i++){
		while(top&&a[s[top]]<a[i]) top--;
		l[i]=s[top];s[++top]=i;
	}
	for(int i=n,top=0;i;i--){
		while(top&&a[s[top]]<a[i]) top--;
		r[i]=s[top];s[++top]=i;
	}
	printf("%lld\n",solve(1,n));
	return 0;
}