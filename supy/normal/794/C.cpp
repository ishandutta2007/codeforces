#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;

bool lst,Turn; //0 A ; 1 B
int n,l,r,fa=1,fb=1;
char a[300005],b[300005],ans[300005];

int cmp(char c, char d) {
	return c>d;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
//	freopen("1.in","r",stdin);
	scanf("%s%s",a+1,b+1); n=strlen(a+1);
	sort(a+1,a+n+1); sort(b+1,b+n+1,cmp);
	l=n/2; r=n/2; lst=1;
	if (l+r<n) {l++; lst=0;}
	//fa..l; fb..r
	int L=1,R=n;
	rep(i,1,n) { //last one
		if (a[fa]<b[fb]) {
			if (Turn==0) ans[L++]=a[fa++];
			else ans[L++]=b[fb++];
		}
		else {
			if (Turn==0) ans[R--]=a[l--];
			else ans[R--]=b[r--];
		}
		Turn^=1;
	}
	rep(i,1,n) printf("%c",ans[i]);
	return 0;
}