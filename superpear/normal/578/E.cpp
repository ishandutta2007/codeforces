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

#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int maxn=100005;

vector<int> List[maxn];
char st[maxn];
int a[maxn];
vector<int> LL,LR,RL,RR;
int N,o,cs;

void ga(int s)
{
	for (int i=0;i<List[s].size();i++)
		printf("%d ",List[s][i]);
}
void pLL()
{
	int cs=LL[LL.size()-1];
	LL.pop_back();
	ga(cs);
}
void pLR()
{
	int cs=LR[LR.size()-1];
	LR.pop_back();
	ga(cs);
}
void pRL()
{
	int cs=RL[RL.size()-1];
	RL.pop_back();
	ga(cs);
}
void pRR()
{
	int cs=RR[RR.size()-1];
	RR.pop_back();
	ga(cs);
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%s",st);
	N=strlen(st);
	for (int i=0;i<N;i++)
		if (st[i]=='L') a[i+1]=-1; else a[i+1]=1;
	o=0;
	LL.clear();LR.clear();RL.clear();RR.clear();
	for (int i=1;i<=N;i++)
		if (a[i]==-1)
		{
			if (LR.size()>0)
			{
				cs=LR[LR.size()-1];
				LR.pop_back();
				LL.p_b(cs);
			}
			else
				if (RR.size()>0)
				{
					cs=RR[RR.size()-1];
					RR.pop_back();
					RL.p_b(cs);
				}
				else
				{
					++o;
					List[o].clear();
					cs=o;
					LL.p_b(cs);
				}
			List[cs].p_b(i);
		}
		else
		{
			if (RL.size()>0)
			{
				cs=RL[RL.size()-1];
				RL.pop_back();
				RR.p_b(cs);
			}
			else
				if (LL.size()>0)
				{
					cs=LL[LL.size()-1];
					LL.pop_back();
					LR.p_b(cs);
				}
				else
				{
					++o;
					List[o].clear();
					cs=o;
					RR.p_b(cs);
				}
			List[cs].p_b(i);
		}
	printf("%d\n",o-1);
	if (LL.size()>RR.size())
	{
		int cs=RR.size();
		for (int i=1;i<=cs;i++)
		{
			pLL();pRR();
		}
		while (LR.size()>0) pLR();
		pLL();
		while (RL.size()>0) pRL();
	}
	else
		if (LL.size()<RR.size())
		{
			int cs=LL.size();
			for (int i=1;i<=cs;i++)
			{
				pRR();pLL();
			}
			while (RL.size()>0) pRL();
			pRR();
			while (LR.size()>0) pLR();
		}
		else
			if (LL.size()>0)
			{
				int cs=RR.size();
				pRR();
				for (int i=1;i<=cs-1;i++)
				{
					pLL();pRR();
				}
				while (LR.size()>0) pLR();
				pLL();
				while (RL.size()>0) pRL();
			}
			else
			{
				while (LR.size()>0) pLR();
				while (RL.size()>0) pRL();
			}

    return 0;
}