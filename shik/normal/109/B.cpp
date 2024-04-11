// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> lst;
void gen( long long n ) {
	if ( n>1000000000 ) return;
	if ( n>0 ) lst.push_back(n);
	gen(n*10+4);
	gen(n*10+7);
}
int L1,R1,L2,R2,k;
double f( double x, double y, double L, double R ) { return max(0.0,min(R,y)-max(L,x)+1); }
double cal( int x1, int y1, int x2, int y2 ) {
	double ret=0;
	ret+=f(x1,y1,L1,R1)*f(x2,y2,L2,R2);
	ret+=f(x2,y2,L1,R1)*f(x1,y1,L2,R2);
	if ( y1==x2 ) ret-=f(y1,y1,L1,R1)*f(x2,x2,L2,R2);
	return ret;
}
int main()
{
	gen(0);
	lst.push_back(-1);
	lst.push_back(1000000001);
	sort(lst.begin(),lst.end());
	double ans=0;
	scanf("%d%d%d%d%d",&L1,&R1,&L2,&R2,&k);
	for ( int i=1; i+k<(int)lst.size(); i++ ) ans+=cal(lst[i-1]+1,lst[i],lst[i+k-1],lst[i+k]-1);
	printf("%.14f\n",ans/(R1-L1+1)/(R2-L2+1));
	return 0;
}