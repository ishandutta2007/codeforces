#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int a[100005];
int main(){
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(n<3){
		return puts("0"),0;
	}
	if(sum%3!=0){
		return puts("0"),0;
	}
	ll js=sum/3;
	ll s=0;
	ll now=0,ans=0;
	for(int i=1;i<n;i++){
		s+=a[i];
		if(s==(js<<1)){
			ans+=now;
		}
		if(s==js){
			now++;
		}
	}
	cout<<ans<<endl;
	return 0;
}