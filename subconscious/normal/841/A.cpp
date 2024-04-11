#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
char s[N];
int a[26],n,S,p;bool q;
int main(){
	scanf("%d%d",&n,&S);
	scanf("%s",s+1);p=strlen(s+1);
	rep(i,p)++a[s[i]-'a'];q=0;
	for(int i=0;i<=25;++i)if(a[i]>S){q=1;break;}
	if(q)puts("NO");else puts("YES");
	return 0;
}