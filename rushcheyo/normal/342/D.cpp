#include<cstdio>
#include<cstring>
const int P=1000000007,D[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void inc(int &x,int y){x+=y;if(x>=P)x-=P;}
const int N=10005;
int n,x,y,dp[N][8],f[N],ans;
char s[3][N];
int calc(){
	memset(dp,0,sizeof dp);
	dp[0][7]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<8;j++){
			if(dp[i][j]==0||(7-j&f[i]))continue;
			for(int k=0;k<8;k++)
				if((7-j&k)==7-j&&(f[i]&k)==f[i]){
					int p=k^(7-j)^f[i];
					if(p==6||p==3||p==0)inc(dp[i+1][k],dp[i][j]);
				}
		}
	return dp[n][7];
}
bool jud(int x,int y){return x>=0&&x<n&&y>=0&&y<3&&s[y][x]=='.';}
int main(){
	scanf("%d",&n);
	for(int i=0;i<3;i++)scanf("%s",s[i]);
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			if(s[i][j]=='O')x=j,y=i;
	for(int i=1;i<16;i++){
		for(int j=0;j<n;j++){
			f[j]=0;
			for(int k=0;k<3;k++)if(s[k][j]!='.')f[j]|=1<<k;
		}
		bool ok=true;
		for(int j=0;j<4;j++)
			if(i&(1<<j)){
				if(jud(x+D[j][0],y+D[j][1])&&jud(x+D[j][0]*2,y+D[j][1]*2)){
					f[x+D[j][0]]|=1<<y+D[j][1];
					f[x+D[j][0]*2]|=1<<y+D[j][1]*2;
				}else ok=false;
			}
		if(ok){
			if(__builtin_popcount(i)&1)inc(ans,calc());
			else inc(ans,P-calc());
		}
	}
	printf("%d\n",ans);
	return 0;
}