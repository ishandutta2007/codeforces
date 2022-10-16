#include<bits/stdc++.h>
using namespace std;
map<string,int> cnt;
map<string,set<string> > sub;
char s[10000],inp[10000];
int tmp,ans1,ans2;
int main()
{
	while(gets(inp))
	{
		for(tmp=3;inp[tmp]!='\\';tmp++);
		for(int j=0;j<tmp;j++)
				s[j]=inp[j];
		s[tmp]=0;
		cnt[s]++;
		for(int i=strlen(inp)-1;i>tmp;i--)
			if(inp[i]=='\\')
			{
				inp[i]=0;
				sub[s].insert(inp);
			}
	}
	for(map<string,set<string> >::iterator i=sub.begin();i!=sub.end();i++)
		ans1=max(ans1,(int)((i->second).size()));
	for(map<string,int>::iterator i=cnt.begin();i!=cnt.end();i++)
		ans2=max(ans2,i->second);
	cout<<ans1<<" "<<ans2;
	return 0;
}