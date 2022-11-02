#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>1;i--){
		if(a[i]-a[i-1]>c) {cout<<n-i+1<<endl;return 0;}
	}
	cout<<n<<endl;
	return 0;
}