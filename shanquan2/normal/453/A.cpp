#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int m,n;scanf("%d%d",&m,&n);
	double ans=m;
	for(int i=1;i<m;i++)ans-=pow(((double)i/m),n);
	printf("%lf\n",ans);
	return 0;
}