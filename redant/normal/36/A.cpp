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

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	char s[111];

	scanf("%d",&n);
	scanf(" %s",s);

	bool ok = true; int diff = -1,i,j;
	
	for(i=0;i<n;i++)
	{
		if(s[i]=='0') continue;
		for(j=i+1;j<n;j++) if(s[j]=='1') break;
		
		if(j!=n)
		{
			if(diff==-1) diff = j-i;
			else if(diff!=j-i) ok=false;
		}
		
		i=j-1;
	}

	puts(ok?"YES":"NO");

	return 0;
}