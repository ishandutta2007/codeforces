#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	string ans;
	int cnt = 0;
	int q[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
	for(int i=0;i<19;i++)
	{
		cout<<q[i]<<endl;
		fflush(stdout);
		cin>>ans;
		if(ans == "yes") ++cnt;
		if(cnt >= 2)
		{
			cout<<"composite"<<endl;
			return 0;
		}
	}
	cout<<"prime"<<endl;
	return 0;
}