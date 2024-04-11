#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
const int N = 600006;
int n,v1,v2;
ll hz[N],pos[N];
struct ele {
	int v,index;
} s[N];
bool cmp(ele a, ele b) {return a.v<b.v;}
void solve() {
	hz[n+1]=-1e9;
	per(i,n,1) {
		hz[i]=max(hz[i+1],1LL*s[i].v*(n-i+1));
		if (hz[i]==hz[i+1]) pos[i]=pos[i+1]; else pos[i]=i;
	}
	per(i,n,1) {
		int p=i+(v1-1)/s[i].v+1; if (p>n) continue;
		if (hz[p]>=v2) {
			puts("Yes");
			printf("%d %d\n",p-i,n-p+1);
			rep(j,i,p-1) printf("%d ",s[j].index); puts("");
			rep(j,p,n) printf("%d ",s[j].index); puts("");
			exit(0);
		}
	}
	
	per(i,n,1) {
		int p=i+(v2-1)/s[i].v+1; if (p>n) continue;
		if (hz[p]>=v1) {
			puts("Yes");
			printf("%d %d\n",n-p+1,p-i);
			rep(j,p,n) printf("%d ",s[j].index); puts("");
			rep(j,i,p-1) printf("%d ",s[j].index); puts("");
			exit(0);
		}
	}	
}
int main() {
	read(n); read(v1); read(v2);
	rep(i,1,n) read(s[i].v),s[i].index=i;
	sort(s+1,s+n+1,cmp);
	solve();
	
	puts("No");
	return 0;
}