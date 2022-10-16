#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;int k;
	cin>>n>>k;
	if (k==2)
	{
		cout<<n-1<<endl;
		for (int i=1;i<=n-1;i++) cout<<i<<" "<<i+1<<endl;
	}
	else
	{
		n--;
		if (n%k==0) cout<<2*(n/k)<<endl; else
		if (n%k==1) cout<<2*(n/k)+1<<endl; else
		cout<<2*(n/k)+2<<endl;
		
		int cnt=1;
		for (int i=0;i<k;i++)
		{
			if (n%k>i)
			{
				cnt++;
				cout<<1<<" "<<cnt<<endl;
				for (int j=2;j<=(n/k+1);j++) 
				{
					cnt++;cout<<cnt-1<<" "<<cnt<<endl;
				}
			} else
			if (n%k<=i) //n/k+1 
			{
				cnt++;
				cout<<1<<" "<<cnt<<endl;
				for (int j=2;j<=(n/k);j++)
				{
					cnt++;cout<<cnt-1<<" "<<cnt<<endl;
				}
			}
		}
	}
		
}