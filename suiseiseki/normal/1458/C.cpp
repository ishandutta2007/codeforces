#include <cstdio>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
const int Maxn=1000;
const int Maxm=100000;
int x,y,v;
int pos_x,pos_y,pos_v;
int n,m;
int a[Maxn+5][Maxn+5];
int b[Maxn+5][Maxn+5];
char s[Maxm+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%s",s+1);
	x=y=v=0;
	pos_x=1,pos_y=2,pos_v=3;
	for(int i=1;i<=m;i++){
		if(s[i]=='R'){
			y=(y+1)%n;
		}
		else if(s[i]=='L'){
			y=(y+n-1)%n;
		}
		else if(s[i]=='D'){
			x=(x+1)%n;
		}
		else if(s[i]=='U'){
			x=(x+n-1)%n;
		}
		else if(s[i]=='I'){
			swap(y,v);
			swap(pos_y,pos_v);
		}
		else{
			swap(x,v);
			swap(pos_x,pos_v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp_x=i,tmp_y=j,tmp_v=a[i][j];
			
			int cur_x,cur_y,cur_v;
			if(pos_x==1){
				cur_x=tmp_x;
			}
			else if(pos_x==2){
				cur_x=tmp_y;
			}
			else{
				cur_x=tmp_v;
			}
			if(pos_y==1){
				cur_y=tmp_x;
			}
			else if(pos_y==2){
				cur_y=tmp_y;
			}
			else{
				cur_y=tmp_v;
			}
			if(pos_v==1){
				cur_v=tmp_x;
			}
			else if(pos_v==2){
				cur_v=tmp_y;
			}
			else{
				cur_v=tmp_v;
			}
			tmp_x=cur_x;
			tmp_y=cur_y;
			tmp_v=cur_v;
			tmp_x=(tmp_x+x)%n;
			if(tmp_x==0){
				tmp_x=n;
			}
			tmp_y=(tmp_y+y)%n;
			if(tmp_y==0){
				tmp_y=n;
			}
			tmp_v=(tmp_v+v)%n;
			if(tmp_v==0){
				tmp_v=n;
			}
			b[tmp_x][tmp_y]=tmp_v;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
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