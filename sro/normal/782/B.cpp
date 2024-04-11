#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define pb push_back
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

const int MAXN=60005;
const double INF=1e9;
int n,x[MAXN],v[MAXN];
double maxc=INF;
double mxmx;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x[i]);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	double l=0,r=INF;
	for(int i=0;i<100;i++)
	{
		double mid=(l+r)/2.0;
		mxmx=0;
		int mind;
		for(int i=0;i<n;i++)
		{
			double db=1.0*fabs(mid-x[i])/v[i];
			if(db>mxmx) mxmx=db,mind=x[i];
		}
		if(mind>mid)l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(12)<<mxmx<<endl;
	return 0;
}