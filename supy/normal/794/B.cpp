#include<cstdio>
#include<cmath>
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;

int n,h;
double ans,lst,Base;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(h);
	Base=sqrt(n);
	rep(i,1,n-1) {
		ans=h*sqrt((double)i/n);
		printf("%.12lf ",ans);
		lst=ans;
	}
	return 0;
}