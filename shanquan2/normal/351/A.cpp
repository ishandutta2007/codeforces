#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[4000];
int main(){
	int n;scanf("%d",&n);n*=2;
	for(int i=0;i<n;i++){
		double x;
		scanf("%lf",&x);
		int t=(int)x;
		t=(int)((x-t)*1000+0.5);
		a[i]=t;
	}
	sort(a,a+n);
	int beg=0;
	while(a[beg]==0)beg++;
	int sum=0;
	for(int i=beg;i<n;i++)
		sum+=a[i];
	double ans;
	if(sum-n/2*1000<0 && sum-(n/2-beg)*1000>0)
		ans=(double)min(abs(sum%1000),abs(1000-sum%1000))/1000;
	else
		if(sum-n/2*1000<0 && sum-(n/2-beg)*1000<0)
			ans=(double)(sum-(n/2-beg)*1000)/1000;
		else
			ans=(double)(sum-n/2*1000)/1000;
	ans=fabs(ans);
	printf("%.3lf",ans);
	return 0;
}