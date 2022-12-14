# include <iostream>
# include <map>
# include <string>
# include <cstdio>
# include <queue>
# include <fstream>
using namespace std;
int a[1000000];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int a_score=0;
	int a_time=0;
	int b_score=0;
	int b_time=0;
	while (1)
	{
		if (a_time<=b_time)
		{
			a_time+=a[a_score];
			a_score++;
		}
		else
		{
			b_time+=a[n-1-b_score];
			b_score++;
		}
		if (a_score+b_score==n)
			break;
	}
	cout<<a_score<<" "<<b_score<<endl;
}