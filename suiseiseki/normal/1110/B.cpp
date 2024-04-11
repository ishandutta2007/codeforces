#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
int b[Maxn+5];
struct Segment{
	int left,right;
	int num;
	friend bool operator <(Segment p,Segment q){
		return p.num>q.num;
	}
}a[Maxn+5];
bool use[Maxn+5];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<n;i++){
		a[i].left=i;
		a[i].right=i+1;
		a[i].num=b[i+1]-b[i]+1;
	}
	sort(a+1,a+n);
	int ans=0;
	for(int i=k;i<=n;i++){
		ans+=a[i].num;
		if(use[a[i].left]){
			ans--;
		}
		if(use[a[i].right]){
			ans--;
		}
		use[a[i].left]=1;
		use[a[i].right]=1;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}