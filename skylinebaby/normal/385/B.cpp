#include<bits/stdc++.h>
using namespace std;
char bb[5555];
vector <int> need;
int main()
{
	scanf("%s",&bb);
	int x = strlen(bb);
	need.push_back(-1);
	for(int i = 0;i<x-3;i++)
	{
		if (bb[i]=='b'&&bb[i+1]=='e'&&bb[i+2]=='a'&&bb[i+3]=='r')
		{
			need.push_back(i);
		}
	}
	int ans = 0;
	for(int i = 1;i<need.size();i++)
	{
		ans += (need[i]-need[i-1])*(x-need[i]-3); 
	}
	printf("%d\n",ans);
	return 0;
}