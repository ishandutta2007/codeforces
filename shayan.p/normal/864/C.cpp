#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a,b,f,k,fuel,ans=0,d;
	cin>>a>>b>>f>>k;
	fuel=b;
	if(fuel<f) {cout<<-1; return 0;}
	fuel-=f;
	for(int i=1;i<k;i++)
	{
		d=(i%2)?a-f:f;
		if(2*d>fuel) {ans++; fuel=b;}
		if(2*d>fuel) {cout<<-1; return 0;}
		fuel-=2*d;
	}
	d=(k%2)?a-f:f;
	if(d>fuel) {ans++; fuel=b;}
	if(d>fuel) {cout<<-1; return 0;}
	cout<<ans;
}