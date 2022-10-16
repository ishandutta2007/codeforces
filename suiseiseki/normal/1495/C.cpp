#include <cstdio>
const int Maxn=500;
const int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
char s[Maxn+5][Maxn+5];
int n,m;
int fa[Maxn*Maxn+5];
int find_id(int x,int y){
	return x*m+y;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x!=fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	if(n%3==0){
		for(int i=2;i<=n;i+=3){
			for(int j=1;j<=m;j++){
				s[i][j]='X';
			}
		}
		for(int i=3;i<n;i+=3){
			if(s[i][2]=='X'||s[i+1][2]=='X'){
				s[i][2]=s[i+1][2]='X';
			}
			else{
				s[i][1]=s[i+1][1]='X';
			}
		}
	}
	else{
		for(int i=1;i<=n;i+=3){
			for(int j=1;j<=m;j++){
				s[i][j]='X';
			}
		}
		for(int i=2;i<n;i+=3){
			if(s[i][2]=='X'||s[i+1][2]=='X'){
				s[i][2]=s[i+1][2]='X';
			}
			else{
				s[i][1]=s[i+1][1]='X';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(s[i][j]);
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