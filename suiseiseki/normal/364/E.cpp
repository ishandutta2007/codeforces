#include <cstdio>
int abs(int a){
	return a<0?-a:a;
}
typedef long long ll;
const int Maxn=2500;
const int Maxk=6;
int a[Maxn+5][Maxn+5];
char s[Maxn+5][Maxn+5];
int sum[Maxn+5][Maxn+5];
int f[2][Maxk+5];
int n,m,k;
ll ans;
int find_sum(int x_l,int x_r,int y_l,int y_r){
	return sum[x_r][y_r]-sum[x_l-1][y_r]-sum[x_r][y_l-1]+sum[x_l-1][y_l-1];
}
int query(int *f,int x,int start){
	if(x==0){
		return abs(f[x]-start);
	}
	return abs(f[x]-f[x-1]);
}
void solve(int x_l,int x_r,int y_l,int y_r,int op){
	if(x_l>x_r||y_l>y_r){
		return;
	}
	if(x_l==x_r&&y_l==y_r){
		if(find_sum(x_l,x_r,y_l,y_r)==k){
			ans++;
		}
		return;
	}
	if(x_l==x_r){
		op=1;
	}
	if(y_l==y_r){
		op=0;
	}
	if(op==0){
		int mid=(x_l+x_r)>>1;
		solve(x_l,mid,y_l,y_r,op^1);
		solve(mid+1,x_r,y_l,y_r,op^1);
		for(int i=y_l;i<=y_r;i++){
			for(int j=0;j<=k;j++){
				if(j==0){
					f[0][j]=mid+1;
					f[1][j]=mid;
				}
				else{
					f[0][j]=f[0][j-1];
					f[1][j]=f[1][j-1];
				}
				while(f[0][j]-1>=x_l&&find_sum(f[0][j]-1,mid,i,i)<=j){
					f[0][j]--;
				}
				while(f[1][j]+1<=x_r&&find_sum(mid+1,f[1][j]+1,i,i)<=j){
					f[1][j]++;
				}
			}
			for(int j=i;j<=y_r;j++){
				for(int l=0;l<=k;l++){
//					puts("Before:");
//					printf("%d %d %d %d %d %d\n",l,f[0][l],mid,f[1][l],i,j);
					while(f[0][l]<=mid&&find_sum(f[0][l],mid,i,j)>l){
						f[0][l]++;
					}
					while(f[1][l]>mid&&find_sum(mid+1,f[1][l],i,j)>l){
						f[1][l]--;
					}
//					puts("After");
//					printf("%d %d %d %d %d %d\n",l,f[0][l],mid,f[1][l],i,j);
//					puts("End\n");
				}
				for(int l=0;l<=k;l++){
//					printf("%d %d\n",query(f[0],l,mid+1),query(f[1],k-l,mid-1));
					ans+=1ll*query(f[0],l,mid+1)*query(f[1],k-l,mid);
				}
//				puts("Endedeeded!\n\n");
			}
		}
	}
	else{
		int mid=(y_l+y_r)>>1;
		solve(x_l,x_r,y_l,mid,op^1);
		solve(x_l,x_r,mid+1,y_r,op^1);
		for(int i=x_l;i<=x_r;i++){
			for(int j=0;j<=k;j++){
				if(j==0){
					f[0][j]=mid+1;
					f[1][j]=mid-1;
				}
				else{
					f[0][j]=f[0][j-1];
					f[1][j]=f[1][j-1];
				}
				while(f[0][j]-1>=y_l&&find_sum(i,i,f[0][j]-1,mid)<=j){
					f[0][j]--;
				}
				while(f[1][j]+1<=y_r&&find_sum(i,i,mid+1,f[1][j]+1)<=j){
					f[1][j]++;
				}
			}
			for(int j=i;j<=x_r;j++){
				for(int l=0;l<=k;l++){
					while(f[0][l]<=mid&&find_sum(i,j,f[0][l],mid)>l){
						f[0][l]++;
					}
					while(f[1][l]>mid&&find_sum(i,j,mid+1,f[1][l])>l){
						f[1][l]--;
					}
				}
				for(int l=0;l<=k;l++){
					ans+=1ll*query(f[0],l,mid+1)*query(f[1],k-l,mid);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			a[i][j]=s[i][j]-'0';
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	solve(1,n,1,m,0);
	printf("%lld\n",ans);
	return 0;
}