#include<iostream>
#include<string>
using namespace std;

string s;
int Last=-1,Ans=0;

int main()
{
	cin>>s;
	if (s.length()<4) {cout<<0<<endl;return 0;}
	for (int i=0;i<s.length()-3;i++)
		if (s.substr(i,4)=="bear")
		{
			Ans+=(i-Last)*(s.length()-(i+3));
			Last=i;
		}
	cout<<Ans<<endl;
	return 0;
}