#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int sum[5005];
int n;
void dfs(int x,int s){
	if(x>n){
		sum[s]++;
		return;
	}
	dfs(x+1,s+1);
	dfs(x+1,s+5);
	dfs(x+1,s+10);
	dfs(x+1,s+50);
}
int work(){
	memset(sum,0,sizeof sum);
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=5000;i++){
		if(sum[i]){
			ans++;
		}
	}
	return ans;
}
const int d[13]={0,4,10,20,35,56,83,116,155,198,244,292};
int main(){
//	freopen("check.out","w",stdout);
	/*for(int i=1;i<=50;i++){
		n=i;
		printf("%d\n",work());
	}*/
	scanf("%d",&n);
	if(n<=11){
		cout<<d[n]<<endl;
	}
	else{
		cout<<d[11]+49ll*(n-11)<<endl;
	}
	return 0;
}