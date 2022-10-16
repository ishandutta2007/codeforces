#include <cstdio>
const int Maxn=100;
int n,m;
int a[Maxn+5][Maxn+5];
struct Node{
	int x,y;
	Node(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
};
struct Answer{
	Node a,b,c;
}ans[Maxn*Maxn*3+5];
int len;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%1d",&a[i][j]);
			}
		}
		len=0;
		for(int i=1;i<n;i++){
			if(a[i][1]){
				len++;
				ans[len].a=Node(i,1);
				ans[len].b=Node(i+1,1);
				ans[len].c=Node(i+1,2);
				a[i][1]^=1;
				a[i+1][1]^=1;
				a[i+1][2]^=1;
			}
			for(int j=2;j<=m;j++){
				if(a[i][j]){
					len++;
					ans[len].a=Node(i,j);
					ans[len].b=Node(i+1,j);
					ans[len].c=Node(i+1,j-1);
					a[i][j]^=1;
					a[i+1][j]^=1;
					a[i+1][j-1]^=1;
				}
			}
		}
		for(int i=1;i<m;i++){
			if(a[n][i]==0){
				continue;
			}
			if(a[n][i]==1&&a[n][i+1]==1){
				len++;
				ans[len].a=Node(n,i);
				ans[len].b=Node(n-1,i);
				ans[len].c=Node(n-1,i+1);
				len++;
				ans[len].a=Node(n,i+1);
				ans[len].b=Node(n-1,i);
				ans[len].c=Node(n-1,i+1);
				a[n][i]^=1;
				a[n][i+1]^=1;
				i++;
				continue;
			}
			len++;
			ans[len].a=Node(n,i);
			ans[len].b=Node(n-1,i);
			ans[len].c=Node(n,i+1);
			len++;
			ans[len].a=Node(n,i);
			ans[len].b=Node(n-1,i+1);
			ans[len].c=Node(n,i+1);
			len++;
			ans[len].a=Node(n,i);
			ans[len].b=Node(n-1,i);
			ans[len].c=Node(n-1,i+1);
			a[n][i]^=1;
		}
		if(a[n][m]){
			len++;
			ans[len].a=Node(n,m);
			ans[len].b=Node(n-1,m);
			ans[len].c=Node(n,m-1);
			len++;
			ans[len].a=Node(n,m);
			ans[len].b=Node(n-1,m-1);
			ans[len].c=Node(n,m-1);
			len++;
			ans[len].a=Node(n,m);
			ans[len].b=Node(n-1,m);
			ans[len].c=Node(n-1,m-1);
			a[n][m]^=1;
		}
		printf("%d\n",len);
		for(int i=1;i<=len;i++){
			printf("%d %d %d %d %d %d\n",ans[i].a.x,ans[i].a.y,ans[i].b.x,ans[i].b.y,ans[i].c.x,ans[i].c.y);
		}
	}
	return 0;
}