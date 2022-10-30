#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int k2,k3,k5,k6;
	cin>>k2>>k3>>k5>>k6;
	int t=min(k2,min(k5,k6));
	k2-=t;
	int m=min(k3,k2);
	int s=t*256+m*32;
	cout<<s<<endl;
	return 0;
}