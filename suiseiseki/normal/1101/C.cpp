#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
struct Seg{
	int left,right;
	int id;
	int group;
	friend bool operator <(Seg p,Seg q){
		return p.left<q.left;
	}
}a[Maxn+5];
bool cmp(Seg p,Seg q){
	return p.id<q.id;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int t;
	int n;
	scanf("%d",&t);
	bool find;
	int max_right;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].left,&a[i].right);
			a[i].id=i;
			a[i].group=1;
		}
		sort(a+1,a+1+n);
		find=0;
		max_right=a[1].right;
		for(int i=2;i<=n;i++){
			if(a[i].left>max_right){
				a[i].group=2;
				for(int j=i+1;j<=n;j++){
					a[j].group=2;
				}
				find=1;
				break;
			}
			max_right=mx(max_right,a[i].right);
		}
		if(!find){
			puts("-1");
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			printf("%d ",a[i].group);
		}
		puts("");
	}
	return 0;
}