#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,ans;
char ch[502][502];
int check(int i,int j){
	if(ch[i][j]!='X') return 0;
 	if(ch[i-1][j-1]!=ch[i][j]) return 0;
	if(ch[i-1][j+1]!=ch[i][j]) return 0;
	if(ch[i+1][j-1]!=ch[i][j]) return 0;
	if(ch[i+1][j+1]!=ch[i][j]) return 0;
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=2;i<n;i++) for(int j=2;j<n;j++) ans+=check(i,j);
	printf("%lld\n",ans); return 0;
}