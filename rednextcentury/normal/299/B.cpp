# include <iostream>
using namespace std;
char a[1000000];
int main()
{
	int n,k;
	cin>>n>>k;
	bool now=0;
	int counter=0;
	int max=0;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		if (a[i]=='#' && now==0)
		{
			now=1;
		}
		if (now==1)
			counter++;
		if (a[i]=='.' && now==1)
		{
			now=0;
			if (counter>max)
				max=counter;
			counter=0;
		}

	}

			if (max>k)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;







}