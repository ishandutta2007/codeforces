#include <bits/stdc++.h>
using namespace std;
int n,i,a[179000];
int main(){
	for(cin>>n;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[n-1]>=a[n-2]+a[n-3])return cout<<"NO",0;
	cout<<"YES\n";
	for(i=0;i<n;i++)cout<<a[i<(n+1)/2?i*2:n+n-1-i*2]<<" ";
}