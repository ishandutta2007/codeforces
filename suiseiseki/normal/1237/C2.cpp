#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 50000
struct Node{
	int x,y,z;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.x==q.x){
			if(p.y==q.y){
				return p.z<q.z;
			}
			return p.y<q.y;
		}
		return p.x<q.x;
	}
}a[Maxn+5],last[Maxn+5],ans[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	int len=0,ans_len=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1].x==a[j].x){
			j++;
		}
		for(int k=i,l;k<=j;k=l+1){
			l=k;
			while(l<j&&a[l+1].y==a[l].y){
				l++;
			}
			if(k+1<=l){
				for(int x=k;x<l;x+=2){
					printf("%d %d\n",a[x].id,a[x+1].id);
				}
			}
			if((l-k+1)&1){
				last[++len]=a[l];
			}
		}
		if(len>=2){
			for(int k=1;k<len;k+=2){
				printf("%d %d\n",last[k].id,last[k+1].id);
			}
		}
		if(len&1){
			ans[++ans_len]=last[len];
		}
		len=0;
	}
	for(int i=1;i<ans_len;i+=2){
		printf("%d %d\n",ans[i].id,ans[i+1].id);
	}
	return 0;
}