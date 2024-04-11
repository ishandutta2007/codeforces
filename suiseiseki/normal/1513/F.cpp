#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n;
struct Node{
	int a,b;
}a[Maxn+5],d_a_1[Maxn+5],d_a_2[Maxn+5];
int d_a_1_len,d_a_2_len;
bool cmp_Node_a(Node a,Node b){
	return a.a<b.a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].b);
		ans+=std::abs(a[i].a-a[i].b);
		if(a[i].a<a[i].b){
			d_a_1[++d_a_1_len]=a[i];
		}
		else if(a[i].a>a[i].b){
			std::swap(a[i].a,a[i].b);
			d_a_2[++d_a_2_len]=a[i];
		}
	}
	ll sum=0;
	std::sort(d_a_1+1,d_a_1+1+d_a_1_len,cmp_Node_a);
	std::sort(d_a_2+1,d_a_2+1+d_a_2_len,cmp_Node_a);
	int maxn=0;
	for(int i=1,j=1;i<=d_a_1_len;i++){
		while(j<=d_a_2_len&&d_a_2[j].a<=d_a_1[i].a){
			maxn=std::max(maxn,d_a_2[j].b);
			j++;
		}
		sum=std::max(sum,0ll+std::min(maxn,d_a_1[i].b)-d_a_1[i].a);
	}
	maxn=0;
	for(int i=1,j=1;i<=d_a_2_len;i++){
		while(j<=d_a_1_len&&d_a_1[j].a<=d_a_2[i].a){
			maxn=std::max(maxn,d_a_1[j].b);
			j++;
		}
		sum=std::max(sum,0ll+std::min(maxn,d_a_2[i].b)-d_a_2[i].a);
	}
	printf("%lld\n",(ans-(sum<<1)));
	return 0;
}