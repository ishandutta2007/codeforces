#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT l1,r1,l2,r2,T;
	cin>>l1>>r1>>l2>>r2>>T;
	INT L=max(l1,l2);
	INT R=min(r2,r1);
	cerr<<R<<" "<<L;
	if(R<L){
		cout<<0<<endl;
		return 0;
	}
	if(T>=L and T<=R) cout<<R-L<<endl;
	else cout<<R-L+1<<endl;
	return 0;
}