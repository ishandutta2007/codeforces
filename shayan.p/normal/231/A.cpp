#include<iostream>
using namespace std;
int main()
{
	int n,i,ans=0,a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a+b+c>1)
		ans++;
	}
	cout<<ans;
}