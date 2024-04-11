#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n,m,x,y;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;i++){
		printf("?");
		for(int j=1;j<=m+1;j++)
		if(j^i)printf(" %d",j);
		puts("");fflush(stdout);
		scanf("%d%d",&x,&y);
		mp[y]++;
	}
	printf("! %d",m+1-mp.begin()->second);
	puts("");fflush(stdout);
}