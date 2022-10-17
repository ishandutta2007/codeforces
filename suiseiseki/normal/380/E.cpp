#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300000
#define T 30
int pre[Maxn+5],nxt[Maxn+5];
struct Node{
	int val;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.val==q.val){
			return p.id<q.id;
		}
		return p.val<q.val;
	}
}a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	int x;
	double ans=0.0;
	double pow;
	double l,r;
	int left,right;
	for(int i=1;i<=n;i++){
		x=left=right=a[i].id;
		pow=1.0;
		l=r=0.0;
		for(int j=1;j<=T;j++){
			pow*=0.5;
			if(left>0){
				l+=pow*(left-pre[left]);
				left=pre[left];
			}
			if(right<=n){
				r+=pow*(nxt[right]-right);
				right=nxt[right];
			}
		}
		ans+=2*l*r*a[i].val;
		nxt[pre[x]]=nxt[x];
		pre[nxt[x]]=pre[x];
	}
	printf("%.6lf\n",ans/n/n);
	return 0;
}