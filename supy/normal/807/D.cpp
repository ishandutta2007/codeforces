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
#define abs(a) ((a)>0 ? (a) : (-a))
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 125
int n;
int a[N][7];
int x[7],y[7];


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool guncu() {
	int x=0,y=0;
	rep(i,1,5)
		if (a[1][i]<a[2][i]) {
			x+=3000*(250-a[1][i])/250;
			y+=3000*(250-a[2][i])/250;
		}
		else {
			x+=500*(250-a[1][i])/250;
			y+=500*(250-a[2][i])/250;
		}
	return (x<=y);
}
int Score(int a, int b) {
	if (a*2>b) return 500;
	if (a*4>b) return 1000;
	if (a*8>b) return 1500;
	if (a*16>b) return 2000;
	if (a*32>b) return 2500;
	return 3000;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);
	rep(i,1,n) rep(j,1,5) read(a[i][j]);
	rep(i,1,n) rep(j,1,5) x[j]+=(a[i][j]!=-1);
	rep(i,1,n) rep(j,1,5) if (a[i][j]==-1) a[i][j]=250;
//	if (guncu()) {puts("-1"); return 0;}
	for (int ans=0;ans<=121*40;ans++) {
		int X=0,Y=0;
		rep(i,1,5) {
			int s;
			if (a[1][i]<a[2][i]) s=Score(x[i],n+ans);
			else {
				if (a[1][i]!=250) x[i]++;
				s=Score(x[i],n+ans);
			}
			X+=s*(250-a[1][i])/250;
			Y+=s*(250-a[2][i])/250;
		}
		if (X>Y) {printf("%d",ans); return 0;}
	}
	printf("-1");
	return 0;
}