#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
typedef pair<int,int> pii;
pii a[50010];
int main()
{
	int n;
	cin>>n;
	for(int n1=1;n1<=n;n1++)
		cin>>a[n1].first>>a[n1].second;
	sort(a+1,a+n+1);
	int now=0;
	for(int n1=1;n1<=n;n1++)
		if(a[n1].second>=now)
			now=a[n1].second;
		else
			now=a[n1].first;
	cout<<now<<endl;
}