#include <cstdio>
#include <algorithm>
const int Maxn=2000;
const double eps=1e-9;
int n,num_a,num_b;
double a[Maxn+5],b[Maxn+5];
std::pair<double,int> v[Maxn+5];
std::pair<double,int> check(double k){
	double sum=0;
	int num=0;
	for(int i=1;i<=n;i++){
		sum+=std::max(a[i]-k,0.0);
		v[i].second=0;
		if(a[i]-k>0){
			num++;
			v[i].second--;
		}
		if(a[i]+b[i]-a[i]*b[i]-k>b[i]){
			v[i].second++;
		}
		v[i].first=std::max(a[i]+b[i]-a[i]*b[i]-k,b[i])-std::max(a[i]-k,0.0);
	}
	std::sort(v+1,v+1+n);
	for(int i=n-num_b+1;i<=n;i++){
		sum+=v[i].first;
		num+=v[i].second;
	}
	return std::make_pair(sum,num);
}
int main(){
	scanf("%d%d%d",&n,&num_a,&num_b);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&b[i]);
	}
	double left=0,right=1;
	while(right-left>eps){
		double mid=(left+right)/2;
		std::pair<double,int> val=check(mid);
		if(val.second<=num_a){
			right=mid;
		}
		else{
			left=mid;
		}
	}
	std::pair<double,int> val=check(left);
	printf("%.9lf\n",val.first+left*num_a);
	return 0;
}