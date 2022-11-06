#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char c[101];
	cin.getline(c, 101);
	int len = strlen(c);
	for(int i=0;i<len;i++)
	{
		if(c[i] == 'H' || c[i] == 'Q' || c[i] == '9')
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}