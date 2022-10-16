#include <cstdio>
#include <algorithm>
const int Maxn=500;
int n;
struct Node{
	int deg;
	int id;
	friend bool operator <(Node a,Node b){
		return a.deg<b.deg;
	}
}a[Maxn+5];
int find_val(int x){
	return 1ll*x*(x-1)/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].deg);
		a[i].id=i;
	}
	std::sort(a+1,a+1+n);
	int last=0,sum=0;
	int ans=-1;
	int ans_a=0,ans_b=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].deg;
		if(find_val(i-last)+last*(i-last)==sum){
			if(i!=last+1&&a[i].deg-a[last+1].deg>ans){
				ans=a[i].deg-a[last+1].deg;
				ans_a=a[i].id;
				ans_b=a[last+1].id;
			}
			sum=0;
			last=i;
		}
	}
	printf("! %d %d\n",ans_a,ans_b);
	fflush(stdout);
	return 0;
}