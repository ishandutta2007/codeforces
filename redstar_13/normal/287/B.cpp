#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	INT n,k;
	scanf("%lld%lld",&n,&k);
	INT s=(k-1)*k/2+1;
	if(n==1){cout<<0<<endl;return 0;}
	if(n>s) {cout<<-1<<endl;return 0;}
	if(n<=k){cout<<1<<endl;return 0;}
	n--,k--;
	int st=1,ed=k;
	while(st<ed){
		int mid=(st+ed+1)/2;
		if((k-mid+1)*(k+mid)/2>=n)st=mid;
		else ed=mid-1;
	}
	cout<<k-st+1<<endl;
	
	return 0;
}