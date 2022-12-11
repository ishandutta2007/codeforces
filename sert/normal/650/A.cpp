#include <bits/stdc++.h>

using namespace std;

long long n,i,ans,x;
long long a[2000007],b[2000007];
map<long long, long long> memx,memy,mem;

int main() {
	scanf("%I64d",&n);
	for (i=0 ; i<n ; i++) {
		scanf("%I64d%I64d",&a[i],&b[i]);
	}
	
	for (i=0 ; i<n ; i++) {
		x = memx[a[i]] + memy[b[i]] - mem[(a[i]+2000000000LL) * 2000000000LL + b[i]+2000000000LL];
		ans += x;
	
		memx[a[i]]++;
		memy[b[i]]++;
		mem[(a[i]+2000000000LL) * 2000000000LL + b[i]+2000000000LL]++;
	}
	
	printf("%I64d\n",(ans<0?0:ans));
}