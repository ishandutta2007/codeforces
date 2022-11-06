#include <iostream>
using namespace std;

int main()
{
	int TUX;
	cin>>TUX;
	int FOO = 0, BAR = 0, BAZ = 0, QUZ = 1;
	for(int i=1;i<=TUX;i++)
	{
		int PUR;
		cin>>PUR;
		FOO += PUR;
		++BAR;
		if(FOO * QUZ > BAZ * BAR)
		{
			BAZ = FOO;
			QUZ = BAR;
		}
	}
	cout<<(BAZ/(double)QUZ)<<endl;
	return 0;
}