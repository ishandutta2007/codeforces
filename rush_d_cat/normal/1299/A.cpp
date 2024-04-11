#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10; 
int n,c[32],a[N];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<31;j++)if(a[i]>>j&1)c[j]++;
	}
	int mx=0,id=1;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=0;j<31;j++)if((a[i]>>j&1) && c[j]==1) tmp|=1<<j;
		if(tmp>mx) {
			mx=tmp; id=i;
		}
	}
	printf("%d ", a[id]);
	for(int i=1;i<=n;i++)if(i!=id)printf("%d ",a[i]);
}