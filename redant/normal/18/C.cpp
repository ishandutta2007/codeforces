/*
LANG: C++
ID: AnilKishore
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)

int n,a[100005];
int s1[100005], s2[100005];

int main()
{
	int i,j,r=0;

	SI(n);
	for(i=1;i<=n;i++) SI(a[i]);

	for(i=1;i<=n;i++) s1[i]=s1[i-1]+a[i];
	for(i=n;i>=1;i--) s2[i]=s2[i+1]+a[i];

	for(i=1;i<n;i++) if(s1[i]==s2[i+1]) r++;

	cout<<r<<endl;
	
	return 0;
}