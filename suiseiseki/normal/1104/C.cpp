#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 1000
char s[Maxn+5];
int a[Maxn+5];
bool mp[10][10];
void work(){
	bool now_mp[5][5];
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			now_mp[i][j]=mp[i][j];
		}
	}
	for(int i=1;i<=4;i++){
		if(mp[i][1]==mp[i][2]&&mp[i][2]==mp[i][3]&&mp[i][3]==mp[i][4]&&mp[i][4]==1){
			now_mp[i][1]=now_mp[i][2]=now_mp[i][3]=now_mp[i][4]=0;
		}
		if(mp[1][i]==mp[2][i]&&mp[2][i]==mp[3][i]&&mp[3][i]==mp[4][i]&&mp[4][i]==1){
			now_mp[1][i]=now_mp[2][i]=now_mp[3][i]=now_mp[4][i]=0;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			mp[i][j]=now_mp[i][j];
		}
	}
}
int n;
struct Answer{
	int x,y;
}an[Maxn+5];
void print(){
	for(int i=1;i<=n;i++){
		printf("%d %d\n",an[i].x,an[i].y);
	}
}
void dfs(int x){
	if(x>n){
		print();
		exit(0);
	}
	bool now_mp[4][4];
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			now_mp[i-1][j-1]=mp[i][j];
		}
	}
	if(a[x]==0){
		for(int j=1;j<4;j++){
			for(int k=1;k<=4;k++){
				if(!mp[j][k]&&!mp[j+1][k]){
					mp[j][k]=mp[j+1][k]=1;
					an[x].x=j;
					an[x].y=k;
					work();
					dfs(x+1);
					for(int now_x=1;now_x<=4;now_x++){
						for(int now_y=1;now_y<=4;now_y++){
							mp[now_x][now_y]=now_mp[now_x-1][now_y-1];
						}
					}
				}
			}
		}
	}
	else{
		for(int j=1;j<=4;j++){
			for(int k=1;k<4;k++){
				if(!mp[j][k]&&!mp[j][k+1]){
					mp[j][k]=mp[j][k+1]=1;
					an[x].x=j;
					an[x].y=k;
					work();
					dfs(x+1);
					for(int now_x=1;now_x<=4;now_x++){
						for(int now_y=1;now_y<=4;now_y++){
							mp[now_x][now_y]=now_mp[now_x-1][now_y-1];
						}
					}
				}
			}
		}
	}
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	dfs(1);
	return 0;
}