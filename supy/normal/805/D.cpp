#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define mo 1000000007 //1e9+7
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;

char s[1000005]; 
long long l,ans;
int a[1000005],size;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	scanf("%s",s+1); l=strlen(s+1);
	rep(i,1,l) if (s[i]=='a') a[++size]=i;
	while (size) {
		ans+=l-a[size]; int tmp=l-a[size]-1;
		l+=tmp;
		ans=(ans+mo)%mo; l=(l+mo)%mo;
		size--;
	//	if (l>=mo||ans>=mo||ans<0||l<0) puts("OwO");
	}
	printf("%d",ans);
	return 0;
}