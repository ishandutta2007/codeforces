#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[100005],b[100005],N,M; 
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		N=M=0;
		for(int i=1;i<=n*2;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x) a[++N]=max(y,-y);
			else b[++M]=max(x,-x);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		double ans=0;
		for(int i=1;i<=n;i++)
			ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.15lf\n",ans);
	}
	return 0;
}