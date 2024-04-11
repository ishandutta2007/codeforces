#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
int a[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int maxn=(-1<<30);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=mx(maxn,a[i]);
	}
	int ans=1;
	int now;
	for(int i=1,j;i<=n;i=j){
		if(a[i]!=maxn){
			j=i+1;
			continue;
		}
		now=0;
		j=i;
		while(j<=n&&a[j]==a[i]){
			now++;
			j++;
		}
		ans=mx(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}