#include<cstdio>
#include<iostream>
using namespace std;

int a[1005];

int main(){
	int n;
	int ans = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n - 1; i++){
		if(a[i] > a[i-1] && a[i] > a[i+1]) ans++;
		if(a[i] < a[i-1] && a[i] < a[i+1]) ans++;
	}
	printf("%d",ans);
}