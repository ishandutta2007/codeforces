#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
struct Node{
	int a,id;
	friend bool operator <(Node p,Node q){
		return p.a<q.a;
	}
}a[Maxn+5];
bool in[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		sum+=a[i].a;
		a[i].id=i;
	}
	sort(a+2,a+1+n);
	in[1]=1;
	for(int i=2;i<=n;i++){
		if(a[1].a>=(a[i].a<<1)){
			in[a[i].id]=1;
		}
	}
	for(int i=2;i<=n;i++){
		if(in[a[i].id]){
			a[1].a+=a[i].a;
		}
	}
	if(a[1].a*2>sum){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(in[i]){
				ans++;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			if(in[i]){
				printf("%d ",i);
			}
		}
		puts("");
	}
	else{
		puts("0");
	}
	return 0;
}