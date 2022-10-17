#include<iostream>
using namespace std;

int main()
{
	long long r,x,y=-1;
	cin>>r;
	r--;
	for(x=1;x*x<=r;x++)
	{
		if(r%x==0 && (r/x-x-1)%2==0 && (r/x-x-1)>0)
		{
			y=(r/x-x-1)/2;
			break;
		}
	}
	if(y==-1)
	{
		cout<<"NO";
		return 0;
	}
	else
		cout<<x<<' '<<y;
}