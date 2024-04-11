//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		sum += k;
	}
	if(sum) cout<<"HARD"<<endl;
	else cout<<"EASY"<<endl;
	return 0;
}