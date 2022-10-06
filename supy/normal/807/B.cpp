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

int p,x,y;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge(int s) {
	int i=(s/50)%475;
	rep(k,1,25) {
		i=(i*96+42)%475;
		if (26+i==p) return 1;
	}
	return 0;
}
int main() {
	read(p); read(x); read(y);
	for (int ans=0;;ans++) {
		int X=x+ans*100;
		for (int i=X; i>=y; i-=50)
			if (judge(i)) {
				printf("%d",ans);
				return 0;
			}
	}
}