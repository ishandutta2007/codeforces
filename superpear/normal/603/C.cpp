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

int calcsg1(int x)
{
	if (x==1) return 1;
	if (x==2) return 0;
	if (x==3) return 1;
	if (x==4) return 2;
	if (x%2==1) return 0;
	int cc=calcsg1(x/2);
	if (cc==0) return 1; else
	if (cc==1) return 2; else
	if (cc==2) return 1;
}

int calcsg2(int x)
{
	if (x==1) return 1;
	if (x==2) return 2;
	return (1-x%2);
}

int N,K,ec,a[100005];

int main()
{
	scanf("%d %d",&N,&K);
	ec=0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		if (K%2==0) ec^=calcsg2(a[i]); else ec^=calcsg1(a[i]);
	}
	if (ec==0) cout<<"Nicky"<<endl; else cout<<"Kevin"<<endl;

	return 0;
}