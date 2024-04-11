# include <iostream>
# include <string>
using namespace std;
int main()
{
	string s;
	int n,t;
	cin>>n>>t;
	cin>>s;
	for (int i=0;i<t;i++)
	{
		for (int x=1;x<s.length();x++)
		{
			if (s[x]=='G' && s[x-1]=='B')
			{
				s[x]='B';
				s[x-1]='G';
				x++;
			}
		
		
		}
	
	
	
	}

	cout<<s<<endl;



}