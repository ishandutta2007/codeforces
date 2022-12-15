#include<iostream>

using namespace std;

bool boo[100001];

int main ()
{
	long long n,i,zero=0,one=0,res=0;

	string a,b;

	cin>>n;

	cin>>a>>b;

	for(i=0;i<n;i++)
	{
		if(a[i]=='1')
		{
			if(b[i]=='1')
				one++;
		}
		else
			zero++;
	}

	for(i=0;i<n;i++)
	{
		if(b[i]=='0')
		{
			if(a[i]=='0')
				res+=one;
			else
				res+=zero;
		}
	}

	cout<<res<<endl;

	return 0;
}