#include <cstdio>
#include <algorithm>
const int Maxm=2000;
const int Maxn=200000;
struct Node{
	int a,id;
	friend bool operator <(Node a,Node b){
		return a.a>b.a;
	}
}a[Maxn+5];
int b[Maxm+5][Maxm+5];
int m,k;
bool check(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=0;
		}
	}
	int pos_x=1,pos_y=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<a[i].a;j++){
			if(pos_x&1){
				pos_y+=2;
				if(pos_y>n){
					pos_x+=2;
					pos_y=(pos_y&1)?1:2;
					if(pos_x>n){
						if(!(pos_y&1)){
							pos_x=1,pos_y=1;
						}
						else{
							pos_x=2,pos_y=1;
						}
					}
				}
			}
			else{
				pos_y+=2;
				if(pos_y>n){
					pos_x+=2;
					pos_y=1;
				}
			}
			b[pos_x][pos_y]=a[i].id;
		}
	}
	return 1;
}
void solve(){
	scanf("%d%d",&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i].a);
		a[i].id=i;
	}
	std::sort(a+1,a+1+k);
	int left=1,right=2000;
	while(left<right){
		int mid=(left+right)>>1;
		if(m<=1ll*mid*mid-(1ll*(mid>>1)*(mid>>1))&&1ll*mid*((mid+1)>>1)>=a[1].a){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	check(left);
	printf("%d\n",left);
	for(int i=1;i<=left;i++){
		for(int j=1;j<=left;j++){
			printf("%d ",b[i][j]);
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}