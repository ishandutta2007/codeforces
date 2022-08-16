#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL L[105],R[105];

int n;
LL p1,p2,p3,t1,t2,t;
LL res = 0;

int main()
{
	int i,j,k;
	
	cin>>n;
	cin>>p1>>p2>>p3;
	cin>>t1>>t2;
	
	for(i=1;i<=n;i++) cin>>L[i]>>R[i];
	
	res = 0;
	
	for(i=1;i<=n;i++) res+=p1*(R[i]-L[i]);
	
	for(i=2;i<=n;i++)
	{
		t = L[i] - R[i-1];
		
		if(t<=t1) res+=t*p1;
		else res+=t1*p1;
		t-=t1;		
		if(t<=0) continue;
		
		if(t<=t2) res+=t*p2;
		else res+=t2*p2;
		t-=t2;		
		if(t<=0) continue;
		
		res+=t*p3;
	}
	
	cout<<res<<endl;
	
	return 0;
}