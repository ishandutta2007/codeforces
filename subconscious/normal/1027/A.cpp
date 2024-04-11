#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
char s[105];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		scanf("%s",s+1);
		bool flag=1;
		rep(i,n/2)if(!(s[i]==s[n-i+1]||s[i]+1==s[n-i+1]-1||s[i]-1==s[n-i+1]+1)){flag=0;break;}
		puts(flag?"YES":"NO");
	}
}