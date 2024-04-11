#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,k,x,y;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool query(int x, int y) {
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	char s[4]; gets(s);//scanf("%s",s); //gets
	return s[0]=='T';
} //1 <= ; 0 >
int bins(int l, int r) {
	while (l<r) {
		int mid=(l+r)>>1;
		if (query(mid,mid+1)) r=mid;
		else l=mid+1;
	}
	return l;
}
int main() {
	read(n); read(k);
	x=bins(1,n);
	y=bins(1,x-1); //x>1
	if (x==y||!query(x,y)||!query(y,x)) y=bins(x+1,n); //careful
	printf("2 %d %d\n",x,y);
//	fflush(stdout);
	return 0;
}