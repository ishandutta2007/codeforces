#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
long long a,b,c,x[100001];
int main(){
	cin>>a>>b;
	rep(i,a)cin>>x[i], c+=(x[i]+b-1)/b;
	cout<<(c+1)/2<<endl;
	return 0;
}