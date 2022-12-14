#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int x[a];
	int maxi=-15 , mini=100000000 , mn=0 , mx=0;
	for(int i=1 ; i<=a ; i++)
	{
		cin >> x[i];
		mini=min(mini , x[i]);
		maxi=max(maxi , x[i]);
	}
	for(int i=1 ; i<=a ; i++)
	{
		if(x[i]==mini)
		mn=i;
	}
	for(int i=1 ; i<=a ; i++)
	{
		if(x[i]==maxi)
		{
			mx=i;
			break;
		}
	}
	if(mn>mx)
	{
		cout<<(a-mn)+(mx-1);
	}
	else
	{
		cout<<(mx-1)+(a-mn-1);
	}
	
}