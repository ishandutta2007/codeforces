#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

char s[1000];
int n;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	scanf("%s",s+1); n=strlen(s+1);
	int cnt=0;
	rep(i,1,n>>1) if (s[i]!=s[n-i+1]) cnt++;
	if (cnt==1) puts("YES"); else {
		if (cnt==0&&n%2==1) puts("YES");
		else puts("NO");
	}
	return 0;
}