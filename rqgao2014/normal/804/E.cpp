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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=35,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,a[1005];
int l[N],r[N];
bool vis[N][N];


void p(int x,int y){
	if(x>y) swap(x,y);
	swap(a[x],a[y]);
	printf("%d %d\n",x,y);
}
void make(int a,int x){
	p(a,x);p(a+1,x+1);
	p(a,x+1);p(a+1,x);
}

int main(){
#ifdef rqgao2014
//	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=i;
	if(n%4==2||n%4==3){puts("NO");return 0;}
	puts("YES");
	for(int i=0;i<n/4;i++)
		for(int j=i+1;j<n/4;j++){
			make(i*4+1,j*4+1);
			make(i*4+1,j*4+3);
			make(i*4+3,j*4+3);
			make(i*4+3,j*4+1);
		}
	for(int i=0;i<n/4;i++){
		make(i*4+1,i*4+3);
		if(n&1){
			p(n,i*4+1);p(i*4+1,i*4+2);p(i*4+2,n);
			p(i*4+3,n);p(i*4+3,i*4+4);p(i*4+4,n);
		}
		else{
			p(i*4+1,i*4+2);
			p(i*4+3,i*4+4);
		}
	}
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}