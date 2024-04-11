//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int t;
int n, x, y;

void check(int &k)
{
	if(k < 0) k = 0;
	if(k > n) k = n;
}

void getmin(int &k)
{
	k = x + y - n;
	check(k);
	++k;
	check(k);
}

void getmax(int &k)
{
	k = x + y - 1;
	check(k);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		int min_, max_;
		getmin(min_);
		getmax(max_);
		cout<<min_<<" "<<max_<<endl;
	}
	return 0;
}