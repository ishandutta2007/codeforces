#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000
#define ll long long
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	ll s;
	cin>>s;
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum<s){
		puts("-1");
		return 0;
	}
	sort(a+1,a+1+n);
	sum-=(ll)a[1]*n;
	if(sum>=s){
		printf("%d\n",a[1]);
		return 0;
	}
	cout<<a[1]-(s-sum+n-1)/n<<endl;
	return 0;
}