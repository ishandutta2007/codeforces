#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
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
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 3030;
int n;
char s[N];
int f[N],st[N],top;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline bool fu(char c) {
	return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int main() {
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,1,n) {
		per(j,i,1) {
			if (j+2<=i&&fu(s[j])&&fu(s[j+1])&&fu(s[j+2])&&!(s[j]==s[j+1]&&s[j]==s[j+2])) break;
			f[i]=j;
		}
	}
	int p=n; st[++top]=n+1;
	while (p) {st[++top]=f[p]; p=f[p]-1;}
	while (top>1) {rep(i,st[top],st[top-1]-1) printf("%c",s[i]); putchar(' '); top--;}
	return 0;
}