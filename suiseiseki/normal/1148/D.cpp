#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300000
int n;
struct Node{
	int a,b,id;
}a[Maxn+5],b[Maxn+5],c;
int n_a,n_b;
bool cmp_1(Node p,Node q){
	return p.b>q.b;
}
bool cmp_2(Node p,Node q){
	return p.a<q.a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c.a,&c.b);
		c.id=i;
		if(c.a<c.b){
			a[++n_a]=c;
		}
		else{
			b[++n_b]=c;
		}
	}
	sort(a+1,a+1+n_a,cmp_1);
	sort(b+1,b+1+n_b,cmp_2);
	if(n_a>=n_b){
		printf("%d\n",n_a);
		for(int i=1;i<=n_a;i++){
			printf("%d ",a[i].id);
		}
		puts("");
	}
	else{
		printf("%d\n",n_b);
		for(int i=1;i<=n_b;i++){
			printf("%d ",b[i].id);
		}
		puts("");
	}
	return 0;
}