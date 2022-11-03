//Win or Freeze
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <fstream>
#include <ctime>
#include <list>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <cstring>
using namespace std;

long long n;
int main()
{
	scanf("%I64d",&n);
	long long a=0,b=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0&&!a)a=i;
		if(a&&(n/a)%i==0&&!b&&a!=sqrt(n))b=i;
	}
	if(a&&b)printf("1\n%I64d\n",a*b);
	else if(a==0)puts("1\n0");
	else puts("2");
	return 0;
}