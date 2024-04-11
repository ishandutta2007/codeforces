#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

//s.max_load_factor(0.25);s.reserve(2048);

string s[1000];

int main ()
{
	int n,m,i,j;
	long long sumc=0,sumr=0,cnt=0;

	cin>>n>>m;

	for(i=0;i<n;i++)
		cin>>s[i];

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(s[i][j]=='B')
			{
				sumr+=i;
				sumc+=j;
				cnt++;
			}

	sumr/=cnt;
	sumc/=cnt;

	cout<<sumr+1<<" "<<sumc+1<<endl;

	return 0;
}