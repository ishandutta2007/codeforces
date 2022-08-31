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

#define MXN 100003

int A[MXN], Lmn[MXN], Rmn[MXN], Lmx[MXN], Rmx[MXN];
const int inf = 100000000;

int main()
{
	int n = SI, i, j, k, mn, mnind, mx, mxind;

	for(i=1;i<=n;i++) A[i] = SI;

	SET(Lmn,-1); SET(Rmn,-1); SET(Lmx,-1); SET(Rmx,-1);

	mn = inf; mnind = -1; mx = -inf; mxind = -1;
	for(i=1;i<=n;i++)
	{
		if(A[i]>mn) Lmn[i] = mnind;
		if(A[i]<mn) mn=A[i], mnind = i;
		
		if(A[i]<mx) Lmx[i] = mxind;
		if(A[i]>mx) mx=A[i], mxind = i;
	}
	
	mn = inf; mnind = -1; mx = -inf; mxind = -1;
	for(i=n;i>0;i--)
	{
		if(A[i]>mn) Rmn[i] = mnind;
		if(A[i]<mn) mn=A[i], mnind = i;
		
		if(A[i]<mx) Rmx[i] = mxind;
		if(A[i]>mx) mx=A[i], mxind = i;
	}

	int x = 0, y, z;

	for(i=2;i<n;i++)
	{
		if(Lmn[i]!=-1 && Rmn[i]!=-1){ x=Lmn[i]; y=i; z=Rmn[i]; break; }
		if(Lmx[i]!=-1 && Rmx[i]!=-1){ x=Lmx[i]; y=i; z=Rmx[i]; break; }
	}

	if(x==0) puts("0");
	else printf("3\n%d %d %d\n",x,y,z);

	return 0;
}