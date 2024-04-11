#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int num;
	int x;
	friend bool operator <(Node p,Node q){
		return p.num>q.num;
	}
}a[1005];
int n;
int mp[25][25];
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=1000;i++){
		a[i].x=i;
		a[i].num=0;
	}
	for(int i=1;i<=n*n;i++){
		scanf("%d",&x);
		a[x].num++;
	}
	sort(a+1,a+1001);
	x=y=1;
	for(int i=1;a[i].num!=0;i++){
		while(a[i].num-4>=0){
			mp[x][y]=mp[n-x+1][y]=mp[x][n-y+1]=mp[n-x+1][n-y+1]=a[i].x;
			y++;
			if(y>(n>>1)){
				y=1;
				x++;
			}
			a[i].num-=4;
			if(x>(n>>1)){
				break;
			}
		}
		if(x>(n>>1)){
			break;
		}
	}
	if(x<=(n>>1)){
		puts("NO");
		return 0;
	}
	if(!(n&1)){
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",mp[i][j]);
			}
			puts("");
		}
	}
	else{
		sort(a+1,a+1001);
		x=1,y=(n>>1)+1;
		for(int i=1;a[i].num!=0;i++){
			while(a[i].num>=2){
				if(y==(n>>1)+1){
					mp[x][y]=mp[n-x+1][y]=a[i].x;
					x++;
					if(x>(n>>1)){
						x=(n>>1)+1;
						y=1;
					}
				}
				else{
					mp[x][y]=mp[x][n-y+1]=a[i].x;
					y++;
				}
				a[i].num-=2;
			}
		}
		if(x!=(n>>1)+1||y!=(n>>1)+1){
			puts("NO");
			return 0;
		}
		sort(a+1,a+1001);
		mp[x][y]=a[1].x;
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",mp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}