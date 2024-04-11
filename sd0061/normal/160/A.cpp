
 #include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[100];
	int n,g=0,k,s=0,i;
	cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) s=s+a[i];  
	sort(a,a+n);
	k=0;i=n-1;
	while(k<=s-k)
	{
			k=k+a[i];
			i--;
			g++;
	}
	cout<<g;
	return 0;
}