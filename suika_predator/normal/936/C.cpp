#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
char str[2333],tar[2333];
int cnt[233],n;
vector<int> vec;
char tmp[2333];
inline void rever(int x)
{
//	cout<<"rever "<<x<<endl;
	if(!x)return;
	vec.push_back(x);
	for(int i=1;i<=x;i++)
		tmp[i]=str[n-i+1];
	for(int i=x+1;i<=n;i++)
		tmp[i]=str[i-x];
	for(int i=1;i<=n;i++)
		str[i]=tmp[i];
//	cout<<str+1<<endl;
}
inline void qwq(int x,int y)
{
//	cout<<"qwq "<<x<<' '<<y<<endl;
	rever(n-y+1);
	rever(y-x);
	rever(n);
}
int main()
{
	scanf("%d %s %s",&n,str+1,tar+1);
	for(int i=1;i<=n;i++)
	{
		cnt[str[i]-'a']++;
		cnt[tar[i]-'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(cnt[i]!=0)
		{
			printf("-1\n");
			return 0;
		}
	}
	int fl=0,ll=(n+1)/2+1,rr=(n+1)/2;
	for(int cur=1;cur<=n;cur++)
	{
		if(!fl)
		{
			ll--;
			int pos=0;
			for(int i=cur;i<=n;i++)
			{
				if(str[i]==tar[ll])
				{
					pos=i;
					break;
				}
			}
			qwq(cur,pos);
		}
		else
		{
			rr++;
			int pos=0;
			for(int i=cur;i<=n;i++)
			{
				if(str[i]==tar[rr])
				{
					pos=i;
					break;
				}
			}
			qwq(cur,pos);
		}
		fl^=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]!=tar[i])
		{
			rever(n);
			break;
		}
	}
	printf("%d\n",vec.size());
	for(auto x:vec)printf("%d ",x);
	return 0;
}