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

int N,e,ans,a[1000005];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	ans=maxlongint;
	e=N-(N-1)/2-1;
	for (int i=1;i<=N-e;i++)
		if (a[i+e]-a[i]<ans) ans=a[i+e]-a[i];
	cout<<ans<<endl;

    return 0;
}