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
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI ({int x;scanf("%d",&x);x;})

int n,m,N,M;
char s1[222], s2[222];
int f1[333], f2[333];

int main()
{
	int i,j,k=1;
	gets(s1); gets(s2);
	for(i=0;s1[i];i++) if(s1[i]!=' ') f1[s1[i]]++;
	for(i=0;s2[i];i++) if(s2[i]!=' ') f2[s2[i]]++;
	for(i=0;i<333;i++) k&=(f2[i]<=f1[i]);
	puts(k?"YES":"NO");
	return 0;
}