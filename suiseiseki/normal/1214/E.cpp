#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
int n;
struct Node{
	int d;
	int a,b;
	friend bool operator <(Node p,Node q){
		return p.d>q.d;
	}
}a[Maxn+5];
int ans[Maxn<<1|5],len;
vector<int> x[Maxn<<1|5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].d);
		a[i].a=(i<<1)-1;
		a[i].b=(i<<1);
	}
	sort(a+1,a+1+n);
	len=n;
	for(int i=1;i<=n;i++){
		ans[i]=a[i].a;
		if(i+a[i].d<=len){
			x[i+a[i].d-1].push_back(a[i].b);
		}
		else{
			ans[++len]=a[i].b;
		}
	}
	for(int i=1;i<len;i++){
		printf("%d %d\n",ans[i],ans[i+1]);
	}
	for(int i=1;i<=len;i++){
		for(int j=0;j<(int)x[i].size();j++){
			printf("%d %d\n",ans[i],x[i][j]);
		}
	}
	return 0;
}