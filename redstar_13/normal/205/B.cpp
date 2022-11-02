#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[110000];
int main(){
#ifndef ONLINE_JUDGE
	freopen("d.txt","r",stdin);
#endif
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	INT s=0;
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]) s+=a[i-1]-a[i];
	}
	cout<<s<<endl;
}