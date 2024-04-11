#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int n,m;
bool fl[233];
char str[233333];
vector<int> vec;
int main()
{
	scanf("%d%d %s",&n,&m,str);
	for(int i=0;i<n;i++)fl[str[i]-'a']=1;
	for(int i=0;i<26;i++)if(fl[i])vec.push_back(i);
	if(n<m)
	{
		cout<<str;
		for(int i=n;i<m;i++)printf("%c",vec[0]+'a');
	}
	else
	{
		for(int i=m-1;i>=0;i--)
		{
			bool fll=0;
			for(int t=0;t<vec.size();t++)
			{
				if(vec[t]+'a'==str[i])
				{
					//cout<<i<<' '<<t<<endl;
					if(t==vec.size()-1)str[i]=vec[0]+'a';
					else {str[i]=vec[t+1]+'a';fll=1;}
					break;
				}
			}
			if(fll)break;
		}
		str[m]=0;
		printf("%s",str);
	}
	return 0;
}