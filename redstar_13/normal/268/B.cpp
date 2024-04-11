#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	INT s=0;
	for(int i=1;i<n;i++){
		s+=i*(n-i);
	}
	s+=n;
	cout<<s<<endl;
	return 0;
}