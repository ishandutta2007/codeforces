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

const int maxn=200005;

vector<int> f[maxn];
int a[maxn],ok[maxn],sm[maxn];
int N,maxc,last;

int gcd(int a,int b)
{
	if (b==0) return a; else return gcd(b,a%b);
}
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	LL ans=0;
	for (int i=1;i<=N;i++)
		f[gcd(i,N)].p_b(i);
	for (int i=1;i<N;i++)
		if (f[i].size()>0)
		{
			sort(f[i].begin(),f[i].end(),cmp);
			memset(ok,0,sizeof(ok));
			for (int j=1;j<=i;j++)
			{
				maxc=0;
				for (int k=j;k<=N;k+=i)
					maxc=max(maxc,a[k]);
				for (int k=j;k<=N;k+=i)
					if (a[k]==maxc) ok[k]=1;
			}
			//for (int j=1;j<=N;j++) cout<<ok[j];cout<<endl;
			vector<int> e;
			e.clear();
			last=0;
			for (int j=1;j<=N;j++)
				if ((ok[j]==0)&&(last!=0))
				{
					e.p_b(j-last);
					last=0;
				}
				else
					if ((ok[j]==1)&&(last==0)) last=j;
			if (last!=0)
			{
				if ((ok[1]==1)&&(e.size()>0)) e[0]+=(N-last+1); else e.p_b(N-last+1);
			}
			sort(e.begin(),e.end(),cmp);
			if (e[0]==N)
			{
				ans+=(LL)f[i].size()*N;
				continue;
			}
			sm[0]=e[0];
			for (int j=1;j<e.size();j++)
				sm[j]=sm[j-1]+e[j];
			int ec=-1;
			for (int j=0;j<f[i].size();j++)
			{
				while ((ec+1<e.size())&&(f[i][j]<=e[ec+1])) ++ec;
				if (ec>=0) ans+=sm[ec]-(ec+1)*(f[i][j]-1);
			}
		}
	cout<<ans<<endl;
    return 0;
}