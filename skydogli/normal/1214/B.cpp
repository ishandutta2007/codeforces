#include<bits/stdc++.h>
using namespace std;
int n,d,e;
int main(){
	int ans=0;
	scanf("%d%d%d",&e,&d,&n);
	for(int i=0;i<=n;++i){
		if(i<=e&&n-i<=d)++ans;
	}		
	printf("%d",ans);
	return 0;
}