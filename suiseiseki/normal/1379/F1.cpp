#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=200000;
int n,m,q;
struct Question{
	int x,y;
	friend bool operator <(Question p,Question q){
		return p.x<q.x;
	}
}a[Maxn+5],b[Maxn+5];
int f[Maxn<<1|5];
void add(int x,int a){
	for(int i=x;i<=m;i+=(i&(-i))){
		f[i]+=a;
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
bool check(int x){
	int len=0;
	for(int i=1;i<=x;i++){
		b[++len]=a[i];
	}
	sort(b+1,b+1+len);
	for(int i=1;i<=len;i++){
		if(b[i].x&1){
			add(b[i].y,1);
		}
		else{
			if(query(b[i].y)>0){
				for(int j=1;j<i;j++){
					if(b[j].x&1){
						add(b[j].y,-1);
					}
				}
				return 0;
			}
		}
	}
	for(int i=1;i<=len;i++){
		if(b[i].x&1){
			add(b[i].y,-1);
		}
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	n<<=1;
	m<<=1;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	int left=0,right=q;
	while(left<right){
		int mid=(left+right+1)>>1;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	for(int i=1;i<=left;i++){
		puts("YES");
	}
	for(int i=left+1;i<=q;i++){
		puts("NO");
	}
	return 0;
}