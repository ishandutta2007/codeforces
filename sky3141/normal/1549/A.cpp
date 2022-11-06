#include<iostream>

using namespace std;

int t;
int s;

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
	    cin >> s;
	    if(s % 2 == 1)
		    cout << 2 << " " << s-1 << endl;
		else
		    cout << 2 << " " << s << endl; 		
	}
	
	return 0;
}