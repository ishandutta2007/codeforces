#include<bits/stdc++.h>
using namespace std;

int n,a[2005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)if(a[i]==1){
		int ans=n;
		for(int j=0;j<n;j++)if(a[j]==1)ans--;
		printf("%d\n",ans);
		return 0;
	}
	int ans=n*3;
	for(int i=0;i<n;i++){
		int now=a[i];
		for(int j=i;j<n;j++){
			now=gcd(now,a[j]);
			if(now==1){
				int t=j-i+n-1;
				if(t<ans)ans=t;
			}
		}
	}
	if(ans==n*3)printf("-1\n");else printf("%d\n",ans);
	return 0;
}