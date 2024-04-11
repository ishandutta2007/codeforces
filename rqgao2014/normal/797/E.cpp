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
using namespace std;

const int N=100005,M=100005,mod=1e9+7,B=300;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

int n,a[N],f[B+5][N];
bool vis[B+5];
void pre(int *f,int k){
	f[n]=1;
	for(int i=n-1;i;i--){
		int t=i+a[i]+k;
		if(t>n) f[i]=1; else f[i]=f[t]+1;
	}
	vis[k]=1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)
		pre(f[i],i);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int p,k;scanf("%d%d",&p,&k);
		if(k>B){
			int ans=0;
			while(p<=n) p+=a[p]+k,ans++;
			printf("%d\n",ans);
		}
		else{
			if(!vis[k]) pre(f[k],k);
			printf("%d\n",f[k][p]);
		}
	}
	return 0;
}