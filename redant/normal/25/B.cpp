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

#define PB push_back
#define MP make_pair
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()

char c[105];

void go(int left,int cp)
{
	if(left==2||left==3)
	{
		printf("%s",c+cp);
		return;
	}

	printf("%c%c",c[cp],c[cp+1]);
	left-=2;
	if(left>0) printf("-");
	go(left,cp+2);
}

int main()
{
	int n,i,j,k;
	scanf("%d %s",&n,c);
	go(n,0);
	return 0;
}