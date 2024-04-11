#include<cstdio>
int n,p[1000010];
bool vis[1000010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	int cnt=0;
	for(int i=1;i<=n;i++)if(!vis[i]){
		cnt++;
		for(int j=i;!vis[j];j=p[j])vis[j]=1;
	}
	if(cnt%2==0)puts("Petr");
	else puts("Um_nik");
}