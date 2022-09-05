#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,a,b,i,j,s,k;
	cin>>n;
	s=0;
	k=0;
	for (i=1;i<=n;i++)
	{
		cin>>a>>b;
		s=s-a+b;
		if (s>k) k=s;
	}
	cout<<k;
}