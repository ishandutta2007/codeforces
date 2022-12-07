#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int ka[1100];
int main()
{
	int i,n,o1=0,o2=0,a;
	cin>>n;
	memset(ka,0,sizeof(ka));
	for(i=0;i<n;i++){
		cin>>a;ka[a]++;
	}
	for(i=1;i<1050;i++){
		o1=max(o1,ka[i]);if(ka[i]>0) o2++;
	}
	cout<<o1<<' '<<o2<<endl;
	return 0;
}