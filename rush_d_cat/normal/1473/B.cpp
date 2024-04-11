#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T;
char s[N],t[N];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main() {
	scanf("%d",&T);
	while(T --) {
		scanf("%s%s",s,t);
		int n=strlen(s),m=strlen(t);
		int len=lcm(n,m);
		for(int i=0;i<len;i++)s[i]=s[i%n];
		for(int i=0;i<len;i++)t[i]=t[i%m];
		bool gg=0;
		for(int i=0;i<len;i++)if(s[i]!=t[i])gg=1;
		if(gg)printf("-1\n");
		else {
			for(int i=0;i<len;i++)printf("%c", s[i]);printf("\n");
		}
	}
}