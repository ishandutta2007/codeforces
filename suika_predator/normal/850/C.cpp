#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<map>
using namespace std;
const int SIZE=1048576;
int mem[1048576];//20
inline int search(int x)
{
	//cout<<"search("<<x<<")\n";
	if(x<SIZE&&mem[x]!=-1)return mem[x];
	int tmp[31]={0};
	for(int i=0;i<=30;i++)
	{
		int t=(x&((1<<(i))-1))|((x&(~((1<<(i+1))-1)))>>(i+1));
		if(t!=x)tmp[search(t)]=1;
	}
	for(int i=0;i<=30;i++)
	{
		if(!tmp[i])
		{
			if(x<SIZE)return mem[x]=i;
			return i;//mem[x]=i;
		}
	}
}
int n,tmp,ans;
map<int,int> factor;
int main()
{
	memset(mem,-1,sizeof(mem));
	mem[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		for(int p=2;p*p<=tmp;++p)
		{
			if(tmp%p==0)
			{
				int cnt=1;
				tmp/=p;
				while(tmp%p==0)
				{
					++cnt;
					tmp/=p;
				}
				factor[p]|=(1<<(cnt-1));
			}
		}
		if(tmp!=1)
		{
			factor[tmp]|=1;
		}
	}
	for(auto x:factor)ans^=search(x.second);
	if(!ans)printf("Arpa\n");
	else printf("Mojtaba\n");
	/*for(int i=0;i<(1<<n)-1;++i)
	{
		if(search(i)==0)
			cout<<bitset<17>(i)<<' '<<search(i)<<endl;
	}*/
	return 0;
}