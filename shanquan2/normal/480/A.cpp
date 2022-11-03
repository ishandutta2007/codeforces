#include<cstdio>
#include<algorithm>
using namespace std;

struct ex{
	int a,b;
	bool operator <(const ex &o)const{
		return a<o.a || a==o.a && b<o.b;
	}
}a[5000];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].a,&a[i].b);
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i].b>=ans)ans=a[i].b;
		else if(a[i].a>=ans)ans=a[i].a;
	}
	printf("%d\n",ans);
	return 0;
}