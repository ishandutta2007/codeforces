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

vector<string> ans[11];
int N,sc,sd;
vector<int> f[20];

int main()
{
	scanf("%d",&N);
	ans[1].p_b("0");
	for (int i=2;i<=N;i++)
	{
		for (int j=0;j<ans[i-1].size();j++)
		{
			sc=0;
			string st=ans[i-1][j];
			for (int k=0;k<st.size();k++)
				if (st[k]-48>sc) sc=st[k]-48;
			sc++;
			if (j%2==0)
			{
				ans[i].p_b(st+"0");
				for (int k=sc;k>=1;k--) ans[i].p_b(st+char(k+48));
			}
			else
			{
				for (int k=1;k<=sc;k++) ans[i].p_b(st+char(k+48));
				ans[i].p_b(st+"0");
			}
		}
	}
	//for (int i=0;i<ans[N].size();i++) cout<<ans[N][i]<<endl;
	cout<<ans[N].size()<<endl;
	for (int i=0;i<ans[N].size();i++)
	{
		for (int j=0;j<=N;j++) f[j].clear();
		sc=0;
		for (int j=0;j<N;j++)
		{
			sd=ans[N][i][j]-48;
			sc=max(sc,sd);
			f[sd].p_b(j+1);
		}
		for (int j=0;j<=sc;j++)
		{
			printf("{%d",f[j][0]);
			for (int k=1;k<f[j].size();k++)
				printf(",%d",f[j][k]);
			printf("}");
			if (j!=sc) printf(",");
		}
		printf("\n");
	}

    return 0;
}