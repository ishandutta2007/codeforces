#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1e6+11;
int n,res,cnt,bo,f[N],sg[N],vis[N];
char s[N];
int main() {
	rep(i,2,500000){
		rep(j,0,min(i-2,300))vis[sg[j]^sg[i-2-j]]=1;
		while(vis[sg[i]])sg[i]++;
		rep(j,0,min(i-2,300))vis[sg[j]^sg[i-2-j]]=0;
		// if(sg[i]>=10)printf("%d:%d\n",i,sg[i]);
	}
	// rep(i,500000-1000,500000){
	// 	rep(j,0,min(i-2,300))vis[sg[j]^sg[i-2-j]]=1;
	// 	int rec=sg[i];
	// 	while(vis[sg[i]])sg[i]++;
	// 	rep(j,0,min(i-2,300))vis[sg[j]^sg[i-2-j]]=0;
	// 	if(sg[i]!=rec)printf("gg %d %d %d\n",i,sg[i],rec);
	// 	// printf("%d:%d\n",i,sg[i]);
	// }
	// puts("OwO");
	// for(int i=4;i<=5e5;i+=2){
	// 	for(int j=0;j*2<=i&&i-2-j>=0;j+=2)if(!f[j]&&!f[i-2-j]){
	// 		f[i]=1;break;
	// 	}
	// 	assert(f[i]==(i%6==0||i%6==4));
	// }
	// rep(i,2,100)if(f[i])printf("%d\n",i);
	int T;read(T);while(T--){
		read(n);res=0;cnt=0;
		scanf("%s",s+1);
		rep(i,1,n)res+=s[i]=='R',res-=s[i]=='B';
		rep(i,1,n-1)if(s[i]!=s[i+1]){
			int j=i;
			while(j+1<=n&&s[j+1]!=s[j])j++;
			cnt^=sg[j-i+1];
			i=j;
		}
		if(cnt)res++;
		printf("%s\n",res>0?"Alice":"Bob");
	}
	return 0;
}