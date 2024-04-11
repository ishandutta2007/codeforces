#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int d;
	int id;
	friend bool operator <(Node p,Node q){
		return p.d>q.d;
	}
}a[505];
int from[5005],to[5005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].d);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	if(a[1].d==1){
		puts("NO");
		return 0;
	}
	int ans=1;
	int pre=1;
	for(int i=2;i<=n;i++){
		if(a[pre].d>=2){
			from[ans]=a[pre].id;
			to[ans]=a[i].id;
			ans++;
			pre=i;
		}
		else{
			break;
		}
	}
	int pos=1;
	a[1].d++;
	int len=ans;
	if(pre<n){
		ans++;
	}
	for(int i=pre+1;i<=n;i++){
		while(pos<=n&&a[pos].d<=2){
			pos++;
		}
		if(pos>n){
			puts("NO");
			return 0;
		}
		a[pos].d--;
		from[len]=a[pos].id;
		to[len++]=a[i].id;
	}
	printf("YES %d\n%d\n",ans-1,n-1);
	for(int i=1;i<n;i++){
		printf("%d %d\n",from[i],to[i]);
	}
	return 0;
}