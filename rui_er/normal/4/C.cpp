#include <iostream>
#include <map>
using namespace std;

map<string, int> reg;

int main()
{
	int n;
	cin>>n;
	string name;
	for(int i=0;i<n;i++)
	{
		cin>>name;
		if(!reg[name])
		{
			cout<<"OK"<<endl;
			++reg[name];
		}
		else
		{
			cout<<name<<reg[name]++<<endl;
		}
	}
	return 0;
}