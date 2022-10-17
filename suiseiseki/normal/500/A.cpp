#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

int main() {
	int n,m,i,a[500000];
	scanf("%d %d",&n,&m);
	for(i=0; i<n-1; i++) {
		scanf("%d",&a[i]);
	}
	m--;
	i=0;
	while(i<m) {
		i+=a[i];
	}
	if(i==m) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}