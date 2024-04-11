#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int main(){
	int n;
	long long t;
	scanf("%d",&n);
	cin>>t;
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	long long ans=0;
	int now;
	while(sum>0){
		sum=0,now=0;
		for(int i=1;i<=n;i++){
			if(sum+a[i]<=t){
				now++;
				sum+=a[i];
			}
		}
		if(sum==0){
			break;
		}
		ans+=(t/sum)*now;
		t%=sum;
	}
	cout<<ans<<endl;
	return 0;
}