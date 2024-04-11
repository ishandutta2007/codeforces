#include <bits/stdc++.h>
using namespace std;
int n,a,b,res=0x3f3f3f3f;
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<=n/a;i++)	res=min(res,(n-i*a)%(5*b));
	cout<<res<<endl;
	return 0;
}