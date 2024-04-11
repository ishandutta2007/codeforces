#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int maxn=1000005;
struct tree
{
	int left,right,sum;
} node[30000005];
int o;
int a[maxn];
int N,K;

void insert(int *s,int depth,int num)
{
	if ((*s)==0)
	{
		++o;
		node[o].left=node[o].right=node[o].sum=0;
		(*s)=o;
	}
	++node[*s].sum;
	if (depth>=1)
	{
		if ((num>>(depth-1))%2==0) insert(&(node[*s].left),depth-1,num);
		else insert(&(node[*s].right),depth-1,num);
	}
}

int main()
{
	scanf("%d %d",&N,&K);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	memset(node,0,sizeof(node));
	o=1;
	int xr=0;
	LL ans=0;
	int tmp=1;
	for (int i=1;i<=N;i++)
	{
		insert(&tmp,30,xr);
		xr^=a[i];
		int s=1; // current node
		for (int j=30;j>=1;j--)
		{
			int pc=(xr>>(j-1))%2;
			if ((K>>(j-1))%2==0)
			{
				if (pc==1) ans+=node[node[s].left].sum,s=node[s].right;
				else ans+=node[node[s].right].sum,s=node[s].left;
			}
			else
			{
				if (pc==1) s=node[s].left; else s=node[s].right;
			}
			if (s==0) break;
		}
		ans+=node[s].sum;
	}
	cout<<ans<<endl;
	//for (int i=1;i<=o;i++)
	//cout<<i<<" "<<node[i].left<<" "<<node[i].right<<" "<<node[i].sum<<endl;

	return 0;
}