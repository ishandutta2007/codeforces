#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,a[N],dfn[N],mx,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	scanf("%d",&mx),dfn[mx]=i;
	mx=0;
	for(int i=1;i<=n;i++)
	if(dfn[a[i]]>mx)mx=dfn[a[i]];
	else ans++;
	printf("%d",ans);
}