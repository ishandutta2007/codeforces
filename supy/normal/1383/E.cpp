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

const int N = 1e6+11,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
char s[N];int res,n,f[2][N],a[N],len,nxt[N],sta[N],top;
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	/*rep(i,1,n)if(s[i]=='0'){
		int j=i;while(j+1<=n&&s[j+1]=='0')j++;
		a[++len]=j-i+1;
		i=j;
	}*/
	s[n+1]='1';
	rep(i,1,n)if(s[i]=='1'){
		int j=i+1;while(s[j]!='1')j++;
		a[++len]=j-i-1;
	}
	int ways=1;
	if(s[1]=='0'){
		while(ways<=n&&s[ways]=='0')ways++;
		if(ways>n){printf("%d\n",n);return 0;}
		//ways=a[1]+1;
		//rep(i,1,len-1)a[i]=a[i+1];len--;
	}
	f[1][1]=ways;
	int lst=0;
	while(s[n-lst]=='0')lst++;
	
	
	per(i,len,1){
		while(top&&a[sta[top]]<=a[i])top--;
		if(top)nxt[i]=sta[top];else nxt[i]=len+1;
		sta[++top]=i;
	}
	
//	rep(i,1,len)cerr<<a[i]<<' ';cerr<<endl;
//	rep(i,1,len)cerr<<nxt[i]<<' ';cerr<<endl;
	
	rep(i,1,len){
		int alr=0;
		for(int j=i;j<=len;){//alr+1..min(a[j],lst)
			if(alr+1<=min(a[j],lst))add(res,1ll*f[1][i]*(min(a[j],lst)-alr)%mo);
			add(f[0][j],1ll*f[1][i]*(a[j]-alr)%mo);
			alr=a[j];
			j=nxt[j];
		}
		add(f[1][i+1],f[0][i]);
		add(f[1][i+1],f[1][i]);
	//	printf("%d:%d %d\n",i,f[0][i],f[1][i]);
	}
	rep(i,1,len){
		//if(i==len)add(res,f[0][i]);
		add(res,f[1][i]);
	}
//	res=1ll*res*ways%mo;
	cout<<res;
	return 0;
}