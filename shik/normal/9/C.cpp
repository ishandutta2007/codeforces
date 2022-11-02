// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
void go( int x ) {
	v.push_back(x);
	if ( x>100000000 ) return;
	go(x*10);
	go(x*10+1);
}
int main()
{
	go(1);
	sort(v.begin(),v.end());
	int n;
	scanf("%d",&n);
	printf("%d\n",upper_bound(v.begin(),v.end(),n)-v.begin());
	return 0;
}