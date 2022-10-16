#include<bits/stdc++.h>
using namespace std;
int n,m;
int serialize(int MM,int DD,int hh,int mm,int ss)
{
	int ret=0;
	static int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	for(int i=1;i<MM;i++)
		ret+=86400*days[i];
	ret+=(DD-1)*86400;
	ret+=hh*3600;
	ret+=mm*60;
	ret+=ss;
	return ret;
}
char s[5000001];
int main()
{
	scanf("%d%d",&n,&m);
	vector<int> t;
	vector<string> mem;
	fgets(s,sizeof(s),stdin);
	while(fgets(s,sizeof(s),stdin))
	{
		int MM,DD,hh,mm,ss;
		sscanf(s,"2012-%02d-%02d %02d:%02d:%02d",&MM,&DD,&hh,&mm,&ss);
		s[19]='\0';
		t.push_back(serialize(MM,DD,hh,mm,ss));
		mem.push_back(s);
	}
	for(int i=0;i<t.size();i++)
	{
		int idx=lower_bound(t.begin(),t.end(),t[i]-n+1)-t.begin();
		if(i-idx+1>=m)
		{
			cout<<mem[i];
			return 0;
		}
	}
	cout<<-1;
	return 0;
}