#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,t,k,d;
int ans1,ans2;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(t); read(k); read(d);
	ans1=((n-1)/k+1)*t;
	int tmp=d/t*k;
	if (tmp>=n) ans2=((n-1)/k+1)*t; //=
	else {
		int x=d/t*t,y=d;
		rep(i,d+1,ans1) {
			if (i-x==t) {x=i; tmp+=k;}
			if (i-y==t) {y=i; tmp+=k;}
			if (tmp>=n) {ans2=i; break;}
		}
	}
//	printf("%d %d\n",ans1,ans2);
	if (ans1==ans2) printf("NO");
	else printf("YES");
	return 0;
}