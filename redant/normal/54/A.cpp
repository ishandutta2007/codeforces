#include <cstdio>
#include <vector>
using namespace std;

#define SI ({int x;scanf("%d",&x);x;})

int main()
{
	int n=SI,k=SI,c=SI,r,i;
	
	vector<int> v(c+2);
	v[0]=0;
	for(i=1;i<=c;i++) v[i] = SI;
	v[c+1] = n+1;
	
	for(r=c,i=1;i<=c+1;i++) r += (v[i]-v[i-1]-1)/k;
	
	printf("%d\n",r);
	
	return 0;
}