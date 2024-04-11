#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
struct Node{
	int p,s;
	friend bool operator <(Node p,Node q){
		return p.p<q.p;
	}
	Node(int _p=0,int _s=0){
		p=_p;
		s=_s;
	}
}b[Maxn+5];
int a[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int f_a[20][Maxn+5],f_b[20][Maxn+5];
int n,m;
void init(){
	for(int i=1;i<=n;i++){
		f_a[0][i]=a[i];
	}
	for(int i=1;i<=m;i++){
		f_b[0][i]=b[i].s;
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f_a[i][j]=mx(f_a[i-1][j],f_a[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;(1<<i)<=m;i++){
		for(int j=1;j+(1<<i)-1<=m;j++){
			f_b[i][j]=mx(f_b[i-1][j],f_b[i-1][j+(1<<(i-1))]);
		}
	}
}
int find_a(int left,int right){
	int len=log2(right-left+1);
	return mx(f_a[len][left],f_a[len][right-(1<<len)+1]);
}
int find_b(int left,int right){
	int len=log2(right-left+1);
	return mx(f_b[len][left],f_b[len][right-(1<<len)+1]);
}
int main(){
	int t;
	scanf("%d",&t);
	int maxn;
	int left,right,mid;
	int ans=0;
	int last;
	int now,x,tmp;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		maxn=a[1];
		for(int i=1;i<=n;i++){
			maxn=mx(maxn,a[i]);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&b[i].p,&b[i].s);
		}
		sort(b+1,b+1+m);
		if(b[m].p<maxn){
			puts("-1");
			continue;
		}
		init();
		ans=0;
		last=1;
		while(last<=n){
			ans++;
			left=last,right=n;
			while(left<right){
				mid=(left+right+1)>>1;
				now=find_a(last,mid);
				x=lower_bound(b+1,b+1+m,Node(now,0))-b;
				tmp=find_b(x,m);
				if(last+tmp-1>=mid){
					left=mid;
				}
				else{
					right=mid-1;
				}
			}
			last=left+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}