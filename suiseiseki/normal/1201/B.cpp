#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	ll sum=0;
	for(int i=1;i<n;i++){
		sum+=a[i];
	}
	if(sum<a[n]||((sum+a[n])&1)){
		puts("No");
	}
	else{
		puts("Yes");
	}
	return 0;
}