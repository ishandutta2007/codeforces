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

int TT,x,y,K;
int dp[1005][1005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&TT,&K);
	for (int gb=1;gb<=TT;gb++)
	{
		scanf("%d %d",&x,&y);
		if (K==1)
		{
			if ((x%2==0)||(y%2==0)) cout<<"+"<<endl; else cout<<"-"<<endl;
			continue;
		}
		if (x>y) swap(x,y);
		int xb=x;
		if (x%(K+1)==0) cout<<"+"<<endl; else
		{
			y-=(x-x%(K+1));
			x%=(K+1);
			if ((x+y)%2+(xb/(K+1))%2==1) cout<<"+"<<endl; else cout<<"-"<<endl;
		}
	}

    return 0;
}