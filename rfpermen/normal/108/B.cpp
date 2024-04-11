#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n,x[100005];
	cin>>n;
	for(int i = 1; i<=n; i++)cin>>x[i];
	sort(x+1,x+1+n);
	for(int i = 2; i<=n; i++)if(x[i-1]*2>x[i] && x[i-1]!=x[i])return cout<<"YES",0;
	cout<<"NO";
	return 0; 
}