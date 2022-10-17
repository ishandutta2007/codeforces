#include <cstdio>
#include <algorithm>
using namespace std;
double fabs(double a){
	return a<0?-a:a;
}
typedef long long ll;
const int Maxn=150000;
const double eps=1e-10;
const double Inf=1e18;
struct Node{
	int p,t;
	double x;
	double l,r;
	friend bool operator <(Node a,Node b){
		return a.x>b.x;
	}
}a[Maxn+5];
bool cmp(Node a,Node b){
	return a.p<b.p;
}
ll T,s;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].p);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].t);
		a[i].x=a[i].p*1.0/a[i].t;
		T+=a[i].t;
	}
	sort(a+1,a+1+n);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&fabs(a[i].x-a[j].x)<eps){
			j++;
		}
		j--;
		for(int k=i;k<=j;k++){
			a[k].l=1.0*a[k].p*(s+a[k].t)/T;
		}
		for(int k=i;k<=j;k++){
			s+=a[k].t;
		}
		for(int k=i;k<=j;k++){
			a[k].r=1.0*a[k].p*s/T;
		}
	}
	sort(a+1,a+1+n,cmp);
	double ans=1;
	for(int i=1;i<n;i++){
		if(a[i].p<a[i+1].p){
			double left=Inf,right=0;
			int j=i;
			while(j>0&&a[j].p==a[i].p){
				left=min(left,a[j].l);
				j--;
			}
			j=i+1;
			while(j<=n&&a[j].p==a[i+1].p){
				right=max(right,a[j].r);
				j++;
			}
			if(left+eps<right){
				ans=min(ans,(a[i+1].p-a[i].p)/(right-left));
			}
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}