#include<bits/stdc++.h>
using namespace std;

int n,a[100005],ans;
int main(){
	scanf("%d",&n);
	for(int i=100;i;i--){
		int x=n-i,y=0;
		for(;x;x/=10)y+=x%10;
		if(y!=i)continue;
		a[ans++]=n-i;
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d\n",a[i]);
	return 0;
}