#include<map>
#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x,f;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
map<int,int> M;
typedef map<int,int>::iterator It;
int n,k,tmp,Ans,pre,pos;
long long D;

int main()
{
	n=IN();k=IN();
	For(i,0,n) M[IN()]++;
	for (It i=M.begin(),j=M.begin();i!=M.end();i++)
	{
		D+=1LL*tmp*(i->first-pre);
		while (D>k)
		{
			while (!j->second) j++;
			D-=(i->first-j->first),j->second--,tmp--;
		}
		if ((tmp+=i->second)>Ans) Ans=tmp,pos=i->first;
		pre=i->first;
	}
	printf("%d %d\n",Ans,pos);
}