#include <cstdio>
#include <algorithm>

using namespace std;

struct company{
	int l,r;
	double p;
}a[10];

int n;
double p[20000];
bool vis[20000];

int low,high;
double ans;

void DFS(int h,int i,int cnt,double pro){
	if (i==0){
		if (cnt>1)
			ans+=h*pro;
		return;
	}
	if (a[i].r<h)
		DFS(h,i-1,cnt,pro);
	else if (a[i].l<h)
		DFS(h,i-1,cnt,pro*a[i].p*(h-a[i].l));
	if (a[i].l<=h && h<=a[i].r)
		DFS(h,i-1,cnt+1,pro*a[i].p);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].p=1.0/(a[i].r-a[i].l+1);
		low=max(low,a[i].l);
		high=max(high,a[i].r);
	}

	double same=0;
	for (int u=1;u<=n;++u){
		double sum=0;
		swap(a[u],a[n]);
		for (int h=1;h<=10000;++h){
			p[h]=0;
			for (int i=1;i<n;++i){
				if (h<a[i].l || a[i].r<h)
					continue;
				sum=a[i].p;
				for (int j=1;j<i;++j)
					if (a[j].r>h){
						if (a[j].l>h)
							sum=0;
						else
							sum*=a[j].p*double(h-a[j].l+1);
					}
				for (int j=i+1;j<n;++j)
					if (a[j].r>=h){
						if (a[j].l>=h)
							sum=0;
						else
							sum*=a[j].p*double(h-a[j].l);
					}
				p[h]+=sum;
			}
			if (h<a[n].l)
				ans+=h*p[h];
			else if (h<=a[n].r)
				ans+=(a[n].r-h)*a[n].p*h*p[h];
		}
		swap(a[u],a[n]);
	}
	for (int h=1;h<=10000;++h)
		DFS(h,n,0,1);
	printf("%.12f",ans);
	return 0;
}