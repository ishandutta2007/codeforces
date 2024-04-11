#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,s[N],t[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",s+i);
	for(int i=1;i<=n;i++)
	scanf("%d",t+i);
	for(int i=n;i;i--)
	s[i]-=s[i-1],t[i]-=t[i-1];
	sort(s+2,s+n+1),sort(t+2,t+n+1);
	for(int i=1;i<=n;i++)
	if(s[i]^t[i])return puts("No"),0;
	puts("Yes");
}