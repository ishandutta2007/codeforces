#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct pnt{
	int x,y,len;
	bool operator <(const pnt &o) const{
		return len<o.len;
	}
}a[100000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].x,&a[i].y),
		a[i].len=abs(a[i].x)+abs(a[i].y);
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i].x>0)ans++;
		if(a[i].x<0)ans++;
		if(a[i].y>0)ans++;
		if(a[i].y<0)ans++;
		ans++;
		if(a[i].y>0)ans++;
		if(a[i].y<0)ans++;
		if(a[i].x>0)ans++;
		if(a[i].x<0)ans++;
		ans++;
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++){
		if(a[i].x>0)
			printf("1 %d R\n",a[i].x);
		if(a[i].x<0)
			printf("1 %d L\n",-a[i].x);
		if(a[i].y>0)
			printf("1 %d U\n",a[i].y);
		if(a[i].y<0)
			printf("1 %d D\n",-a[i].y);
		printf("2\n");
		if(a[i].y>0)
			printf("1 %d D\n",a[i].y);
		if(a[i].y<0)
			printf("1 %d U\n",-a[i].y);
		if(a[i].x>0)
			printf("1 %d L\n",a[i].x);
		if(a[i].x<0)
			printf("1 %d R\n",-a[i].x);
		printf("3\n");
	}
	return 0;
}