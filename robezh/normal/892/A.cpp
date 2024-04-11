#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
int a[100005];
int b[100005];

int main(){
	scanf("%d", &n);
	long long maxcap = 0;
	long long sumvol = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), sumvol += a[i];
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	sort(b, b+n);
	if((long long)b[n-1] + b[n-2] >= sumvol) printf("YES");
	else printf("NO");
}