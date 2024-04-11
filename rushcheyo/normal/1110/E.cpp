#include<bits/stdc++.h>
using namespace std;

int n,c[100005],t[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++)scanf("%d",t+i);
	for(int i=n;i;i--)c[i]-=c[i-1],t[i]-=t[i-1];
	sort(c+2,c+1+n);sort(t+2,t+1+n);
	for(int i=1;i<=n;i++)if(c[i]!=t[i])return puts("No"),0;
	puts("Yes");
}