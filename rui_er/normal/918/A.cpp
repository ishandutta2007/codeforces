#include<iostream>
#include<limits.h>
using namespace std;

const int f[] = {-1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, INT_MAX};

int main()
{
	int n;
	cin>>n;
	int p = 1;
	for(int i=1;i<=n;i++)
	{
		if(i == f[p]) 
		{
			cout<<"O";
			p++;
		}
		else if(i < f[p])
			cout<<"o";
		else;
	}
	return 0;
}