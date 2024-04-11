#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
long long b[Maxn+5];
long long a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=(n>>1);i++){
		cin>>b[i];
	}
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i<=(n>>1);i++){
		if(b[i]-a[i-1]<=a[n-i+2]){
			a[n-i+1]=b[i]-a[i-1];
			a[i]=a[i-1];
		}
		else{
			a[i]=b[i]-a[n-i+2];
			a[n-i+1]=a[n-i+2];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	puts("");
	return 0;
}