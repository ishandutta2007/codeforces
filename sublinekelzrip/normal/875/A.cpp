#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
vector<int> v;
char s[100];
int main()
{
	int n;
	cin>>n;
	for(int j=n;j>=max(1,n-1000);j--)
	{
		int x=j;
		sprintf(s,"%d",j);
		int len=strlen(s);
		for(int k=0;k<len;k++)
			x+=s[k]-48;
		if(x==n)
			v.push_back(j);
	}
	reverse(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int j=0;j<v.size();j++)
		printf("%d\n",v[j]);
	
		
}