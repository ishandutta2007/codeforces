#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string name[n];
	string id[n];
	int num[n];
	int first[n];
	for(int i=0;i<n;i++)
	{
		cin>>name[i]>>id[i];
		num[i] = i + 1;
		if(id[i] == "captain") first[i] = 3;
		else if(id[i] == "man") first[i] = 2;
		else if(id[i] == "rat") first[i] = 0;
		else first[i] = 1;
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			if(first[j] == i)
				cout<<name[j]<<endl;
	return 0;
}