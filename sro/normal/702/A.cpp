#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	int lx=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			lx++;
		}else{
			lx=1;
		}
		ans=max(ans,lx);
	}
	printf("%d\n",ans);
}