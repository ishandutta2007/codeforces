#include<bits/stdc++.h>
using namespace std;

int n,a[105];

void gg(){
	puts("Infinite");
	exit(0);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int ans=0;
	for(int i=2;i<=n;++i)
		if(a[i-1]==1){
			if(a[i]==2){
				ans+=3;
				if(i>=3&&a[i-2]==3)--ans;
			}else ans+=4;
		}else if(a[i-1]==2){
			if(a[i]==1)ans+=3;
			else gg();
		}else{
			if(a[i]==1)ans+=4;
			else gg();
		}
	printf("Finite\n%d\n",ans);
	return 0;
}