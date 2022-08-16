/*
PROG: 
LANG: C++
ID: AnilKishore ( RedAnt )
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

int n=0;
VI a;

int main()
{
	int x,i,j,k;
	char str[11111];
	scanf("%s",str);
	char *p = strtok(str,",");
	while(p!=NULL)
	{
		a.PB(atoi(p));
		p = strtok(NULL,",");
	}
	
	sort(ALL(a));
	a.resize(unique(ALL(a))-a.begin());
	a.PB(1000000);

	int got = 0, start = a[0], prev = a[0];
	
	for(i=1;i<SZ(a);i++)
	{
		int cur = a[i];

		if(cur>prev+1)
		{
			if(got) printf(",");
			got = 1;
			if(start!=prev) printf("%d-%d",start,prev);
			else printf("%d",start);

			start=cur;
		}
		
		prev = cur;
	}

	return 0;
}