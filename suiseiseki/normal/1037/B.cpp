#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans=0;
	if(a[(n>>1)+1]<s){
		for(int i=(n>>1)+1;i<=n&&a[i]<s;i++){
			ans+=s-a[i];
		}
	}
	else{
		for(int i=(n>>1)+1;i>0&&a[i]>s;i--){
			ans+=a[i]-s;
		}
	}
	cout<<ans<<endl;
	return 0;
}