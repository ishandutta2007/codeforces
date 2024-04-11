#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans;
char S[102];
int main(){
	scanf("%d%s",&n,S);
	for(int i=0;i<n;i++)
	if(S[i]=='8')a++;
	else b++;
	for(int i=1;i<=a;i++)
	if(a-i+b<10*i)break;
	else ans=i;
	printf("%d",ans);
}