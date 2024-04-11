#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
struct Segment{
	int left,right;
	friend bool operator <(Segment p,Segment q){
		return p.right<q.right;
	}
}seg[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		seg[i].left=a-b;
		seg[i].right=a+b;
	}
	sort(seg+1,seg+1+n);
	int ans=0,last=(-1<<30);
	for(int i=1;i<=n;i++){
		if(seg[i].left>=last){
			ans++;
			last=seg[i].right;
		}
	}
	printf("%d\n",ans);
	return 0;
}