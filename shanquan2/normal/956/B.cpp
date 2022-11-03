#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int a[N],n,u;
double ans=-1;
int main(){
	scanf("%d%d",&n,&u);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n-2;i++){
		int j=i+1;
		int k=lower_bound(a,a+n,a[i]+u+1)-a-1;
		if(k>j){
			ans=max(ans,1.0*(a[k]-a[j])/(a[k]-a[i]));
		}
	}
	if(ans<0)printf("-1\n");
	else printf("%.10lf\n",ans);
	return 0;
}