#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100000 + 10;
int t;
int n,a[4],b[4];

int main() {
	scanf("%d", &t);
	while (t--){
		for(int i=0;i<3;i++)scanf("%d",&a[i]);
		for(int i=0;i<3;i++)scanf("%d",&b[i]);
		int mn=min(a[2],b[1]);
		int ans=mn*2;
		a[2]-=mn,b[1]-=mn;
		ans-=max( (b[2]+a[1])-(a[0]+a[1]+a[2]) ,0) * 2;
		printf("%d\n", ans);
	}
}