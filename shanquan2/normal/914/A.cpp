#include<bits/stdc++.h>
using namespace std;

int n,ans=-1e9;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		if(x<0)ans=max(ans,x);
		else{
			int y=sqrt(x+0.5);
			if(y*y!=x)ans=max(ans,x);
		}
	}
	printf("%d\n",ans);
	return 0;
}