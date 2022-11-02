#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,t,h,hav;
char S[N],T[N];
int main(){
	scanf("%d%d%s%s",&n,&m,S,T);
	if(n-1>m)return puts("NO"),0;
	for(int i=0;i<n;i++)
	if(S[i]=='*')hav=1;
	for(int i=0;;i++)
	if(i==n||S[i]^T[i]){t=i;break;}
	if(t==n&&n==m&&!hav)return puts("YES"),0;
	if(!hav)return puts("NO"),0;
	for(int i=1;;i++)
	if(i>n||S[n-i]^T[m-i]){h=i;break;}
	if(S[t]=='*'&&S[n-h]=='*')puts("YES");
	else puts("NO");
}