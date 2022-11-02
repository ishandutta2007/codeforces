#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,Q,k;
	double mn=360;
	cin>>n>>Q;
	double d=180-(double)360/n;
	d/=(n-2);
	for(int i=1;i<=n-2;i++){
		mn=min(abs(Q-i*d),mn);
	}
	for(int i=1;i<=n-2;i++){
		if(abs(Q-i*d)==mn) k=i;
	}
	cout<<2<<' '<<1<<' '<<k+2<<endl;
	
	
	return 0;
}