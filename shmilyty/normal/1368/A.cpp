#include<bits/stdc++.h>
using namespace std;
int t,a,b,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&b,&n);
		int cnt=0;
		while(a<=n&&b<=n)
		{
			if(a<b)
				a+=b;
			else
				b+=a;
			cnt++; 
		}
		cout<<cnt<<endl;
	}
	return 0;
}