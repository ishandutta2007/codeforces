#include <iostream>
using namespace std;

int main()
{
	int n;
	int a, b;
	cin>>n>>a>>b;
	if(b >= 0)
	{
		for(int i=0;i<b;i++)
		{
			a++;
			if(a > n) a -= n;
		}
	}
	else
	{
		for(int i=0;i<-b;i++)
		{
			a--;
			if(a < 1) a += n;
		}
	}
	cout<<a<<endl;
	return 0;
}