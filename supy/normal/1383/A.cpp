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
int n;char s[N],t[N];
int main() {
	int T;read(T);while(T--){
		read(n);scanf("%s%s",s+1,t+1);
		bool gg=0,a[27][27]={0};
		rep(i,1,n){gg|=s[i]>t[i];a[s[i]-'a'][t[i]-'a']=1;}
		int res=0;
		if(gg)res=-1;
		else{
			rep(i,0,20){
				rep(j,i+1,20)if(a[i][j]){
					res++;
					rep(k,j+1,20)if(a[i][k])a[j][k]=1;
					break;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}