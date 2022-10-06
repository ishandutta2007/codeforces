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
const int N = 2333;
int n, x[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline incaa(int &a, int &b) {
	b++; if (b>12) {a++; b=1;}
}
inline int getday(int a, int b) {
	if (b==1) return 31;
	if (b==3) return 31;
	if (b==4) return 30;
	if (b==5) return 31;
	if (b==6) return 30;
	if (b==7) return 31;
	if (b==8) return 31;
	if (b==9) return 30;
	if (b==10) return 31;
	if (b==11) return 30;
	if (b==12) return 31;
	return (a%4==0 && (a%100!=0 || a%400==0)) ? 29 : 28;
}
inline bool ok(int days, int a, int b) {
	return days==getday(a,b);
}
bool judge(int a, int b) {
	rep(i,1,n) {if (!ok(x[i],a,b)) return 0; incaa(a,b);}
	return 1;
}
int main() { //printf("%d %d %d\n",getday(4,2),getday(400,2),getday(100,2));
	read(n); rep(i,1,n) read(x[i]); bool flag=0;
	rep(i,1,8004) rep(j,1,12) flag|=judge(i,j); //tle??????????????????????????????
	if (flag) puts("YES"); else puts("NO");
	return 0;
}