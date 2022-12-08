#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;

int n,m;
char s[MAXN],t[MAXN];
inline bool judge(int a,int b,int c){
	int i,j=1;
	for(i=a;i<=b;++i,++j) if(s[i]!=t[j]) return 0;
	for(i=b-1;i>=c;--i,++j) if(s[i]!=t[j]) return 0;
	return 1; 
}
inline void solve(){
	int i,j;
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j){
			int k=j-(m-(j-i+1));
			if(k<=0) continue;
			if(judge(i,j,k)) return printf("YES\n"),void();
		}
	printf("NO\n");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}