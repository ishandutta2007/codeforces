#include<bits/stdc++.h>
using namespace std;
int n,a,b,sum,al,num;
bool vis[103];
int main(){
	scanf("%d%d",&n,&a),
	al=sum=a;
	for(int i=2;i<=n;i++){
		scanf("%d",&b),vis[i]=b*2<=a;
		if(vis[i])sum+=b,num++;
		al+=b;
	}
	if(sum*2<=al)return puts("0"),0;
	printf("%d\n1",num+1);
	for(int i=2;i<=n;i++)
	if(vis[i])printf(" %d",i);
}