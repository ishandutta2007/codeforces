#include<bits/stdc++.h>
using namespace std;

const int N=100100;
int n,a[N],b[N];
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		b[i]=max(b[i+1]-1,a[i]+1);
	}
	int p=0;
	for(int i=1;i<=n;i++){
		if(p+1==b[i])p++;
		ans+=p-a[i]-1;
	}
	printf("%lld\n",ans);
	return 0;
}