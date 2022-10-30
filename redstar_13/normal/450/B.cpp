#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
INT f[20];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT x,y;
	cin>>x>>y;
	INT n;
	cin>>n;
	f[1]=x;
	f[2]=y;
	f[3]=y-x;
	f[4]=-x;
	f[5]=-y;
	f[6]=-f[3];
	n%=6;
	if(n==0) n=6;
	f[n]%=1000000007;
	if(f[n]>=0) cout<<f[n]<<endl;
	else cout<<f[n]+1000000007<<endl;
	return 0;
}