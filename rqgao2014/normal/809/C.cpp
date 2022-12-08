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

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

inline int make(int now,int a,int b){
	if(a<b||now) return 1;
	if(a==b) return 0;
	return 2;
}
int dp[33][3][3][3],f[33][3][3][3];
int get(int x,int y,int z){
	clr(dp,0);clr(f,0);
	dp[31][0][0][0]=1;
	for(int i=30;~i;i--){
		int aa=(x>>i)&1,bb=(y>>i)&1,cc=(z>>i)&1;
		for(int a=0;a<2;a++)
			for(int b=0;b<2;b++)
				for(int c=0;c<2;c++)
					for(int ta=0;ta<2;ta++)
						for(int tb=0;tb<2;tb++){
							int ax=make(a,ta,aa),bx=make(b,tb,bb),cx=make(c,ta^tb,cc);
							ch(dp[i][ax][bx][cx],dp[i+1][a][b][c]);
							ch(f[i][ax][bx][cx],f[i+1][a][b][c]);
							ch(f[i][ax][bx][cx],(ll)dp[i+1][a][b][c]*((ta^tb)<<i)%mod);
						}
	}
	int ans=0;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
			for(int c=0;c<2;c++)
				ch(ans,(dp[0][a][b][c]+f[0][a][b][c])%mod);
//	printf("%d %d %d %d\n",x,y,z,ans);
	return ans;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	int T;scanf("%d",&T);
	while(T--){
		int x1,y1,x2,y2,k;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		x1--;y1--;x2--;y2--;k--;
		int ans=get(x2,y2,k);
		if(x1) ch(ans,mod-get(x1-1,y2,k));
		if(y1) ch(ans,mod-get(x2,y1-1,k));
		if(x1&&y1) ch(ans,get(x1-1,y1-1,k));
		printf("%d\n",ans);
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}