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

LL n,d,m,l,fall=0;
LL cp, p1, p2, x, y, z;

int main()
{
	int i,j,k;
	cin>>n>>d>>m>>l;
	
	for(i=1;i<n;i++)
	{
		x = (i-1)*m+l;
		y = i*m;
		z = ((x/d)+1)*d;
		if(z<y){ fall=z; break; }
	}

	if(fall==0){ z = (n-1)*m+l; fall = ((z/d)+1)*d; }

	cout<<fall<<endl;
	
	return 0;
}