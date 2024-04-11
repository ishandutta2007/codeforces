#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pr;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 70030;
int n,a[N],ten[11];
map<pr,int> Map, Map1;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int get(int i, int l, int r) { //a[i] l..r
	return a[i]%ten[9-l+1]/ten[9-r];
}
int main() {
	read(n); ten[0]=1; rep(i,1,9) ten[i]=ten[i-1]*10;
	rep(i,1,n) read(a[i]); 
	rep(i,1,n) {
		rep(l,1,9) rep(r,l,9) Map1[pr(get(i,l,r),r-l+1)]++;
	}
	rep(i,1,n) {
		Map.clear();
		rep(l,1,9) rep(r,l,9) Map[pr(get(i,l,r),r-l+1)]++;
	//	rep(l,1,8) rep(r,l+1,9) printf("%d %d %d %d %d\n",i,l,r,Map[get(i,l,r)],Map1[get(i,l,r)]);
		rep(len,1,9) {
			bool ok=0;
			rep(l,1,9) if (l+len-1<=9)
				if (Map1[pr(get(i,l,l+len-1),len)]==Map[pr(get(i,l,l+len-1),len)]) {
				//	printf("[%d %d %d %d %d]\n",i,l,l+len-1,Map1[pr(get(i,l,l+len-1),len)],Map[pr(get(i,l,l+len-1),len)]);
					ok=1; rep(k,l,l+len-1) printf("%d",get(i,k,k)); puts(""); //printf("%d\n",get(i,l,l+len-1)); 
					break;
				}
			if (ok) break;
		}
	}
	return 0;
}