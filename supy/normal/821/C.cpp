#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int N = 300006;
int n,stack[N],top,k=1,ans;
char s[20];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(int a, int b) {return a>b;}
int main() {
	read(n);
	rep(i,1,n*2) {
		int x; scanf("%s",s);
		if (s[0]=='a') {read(x);stack[++top]=x;}
		else {
			if (top==0||stack[top]==k){if (top) top--; k++;}
			else {k++; top=0; ans++;}
		}
	}
	printf("%d",ans);
	return 0;
}