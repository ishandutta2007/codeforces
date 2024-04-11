#include <cstdio>
const int Maxn=10000;
const int Maxm=100000;
int n,m;
struct Operation{
	int op;
	int d;
	int x,y,c;
}op[Maxm+5];
int ans[Maxm+5];
int f[Maxn+5][Maxn+5];
int st_x[Maxm+5],st_y[Maxm+5],st_z[Maxm+5],top;
int max_x,max_y;
void update(int x,int y,int a){
	top++;
	st_x[top]=x,st_y[top]=y,st_z[top]=a;
	for(int i=x;i<=max_x;i+=(i&(-i))){
		for(int j=y;j<=max_y;j+=(j&(-j))){
			f[i][j]+=a;
		}
	}
}
int query(int x,int y){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		for(int j=y;j>0;j-=(j&(-j))){
			ans+=f[i][j];
		}
	}
	return ans;
}
void clear(){
	while(top>0){
		update(st_x[top],st_y[top],-st_z[top]);
		top-=2;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&op[i].op);
		if(op[i].op==1){
			scanf("%d%d%d%d",&op[i].d,&op[i].x,&op[i].y,&op[i].c);
		}
		else{
			scanf("%d%d",&op[i].x,&op[i].y);
		}
	}
	max_x=n,max_y=n;
	for(int i=1;i<=m;i++){
		if(op[i].op==1){
			if(op[i].d==1){
				update(op[i].x,op[i].y,1);
			}
			if(op[i].d==2){
				update(op[i].x,op[i].y+1,-1);
			}
			if(op[i].d==3){
				update(op[i].x+1,op[i].y,-1);
			}
			if(op[i].d==4){
				update(op[i].x+1,op[i].y+1,1);
			}
		}
		else{
			ans[i]+=query(op[i].x,op[i].y);
		}
	}
	clear();
	max_x=n+n,max_y=n;
	for(int i=1;i<=m;i++){
		if(op[i].op==1){
			if(op[i].d==1){
				update(op[i].x+op[i].y+op[i].c+1,op[i].y,-1);
			}
			if(op[i].d==4){
				update(op[i].x+op[i].y-op[i].c,op[i].y+1,-1);
			}
		}
		else{
			ans[i]+=query(op[i].x+op[i].y,op[i].y);
		}
	}
	clear();
	max_x=n,max_y=n+n;
	for(int i=1;i<=m;i++){
		if(op[i].op==1){
			if(op[i].d==1){
				update(n-op[i].x+2,op[i].x+op[i].y+op[i].c+1,1);
			}
			if(op[i].d==4){
				update(n-op[i].x+1,op[i].x+op[i].y-op[i].c,1);
			}
		}
		else{
			ans[i]+=query(n-op[i].x+1,op[i].x+op[i].y);
		}
	}
	clear();
	max_x=n+n,max_y=n;
	for(int i=1;i<=m;i++){
		if(op[i].op==1){
			if(op[i].d==2){
				update(n+op[i].x-op[i].y+op[i].c+2,op[i].y+1,1);
			}
			if(op[i].d==3){
				update(n+op[i].x-op[i].y-op[i].c+1,op[i].y,1);
			}
		}
		else{
			ans[i]+=query(n+op[i].x-op[i].y+1,op[i].y);
		}
	}
	clear();
	max_x=n,max_y=n+n;
	for(int i=1;i<=m;i++){
		if(op[i].op==1){
			if(op[i].d==2){
				update(op[i].x,n+op[i].y-op[i].x-op[i].c+1,1);
			}
			if(op[i].d==3){
				update(op[i].x+1,n+op[i].y-op[i].x+op[i].c+2,1);
			}
		}
		else{
			ans[i]+=query(op[i].x,n-op[i].x+op[i].y+1);
		}
	}
	clear();
	for(int i=1;i<=m;i++){
		if(op[i].op==2){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}