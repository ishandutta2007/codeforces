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

int n,a[500007],mxtp=0;
set<int> si;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n*2;i++)
	{
		scanf("%d",&a[i]);
		if(si.count(a[i]))
			si.erase(si.find(a[i]));
		else si.insert(a[i]);
		if((int)si.size()>mxtp) mxtp=(int)si.size();
	}
	printf("%d",mxtp);
	return 0;
}