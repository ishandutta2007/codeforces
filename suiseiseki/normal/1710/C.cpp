#include <cstdio>
#include <cstring>
const int Maxn=200000;
const int Mod=998244353;
char n[Maxn+5];
int n_len;
int f[2][8][8];
void add(int &x,int y){
	x=x+y>=Mod?x+y-Mod:x+y;
}
int main(){
	scanf("%s",n+1);
	while(n[++n_len]!='\0');
	n_len--;
	int cur=0,nxt;
	f[cur][0][0]=1;
	for(int i=1;i<=n_len;i++){
		nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		for(int mask=0;mask<8;mask++){
			for(int j=0;j<8;j++){
				if(f[cur][mask][j]==0){
					continue;
				}
				add(f[nxt][mask][n[i]=='1'?7:j],f[cur][mask][j]);
				if(((j>>2)&1)==1||n[i]=='1'){
					add(f[nxt][mask|4][j|(3*(n[i]=='1'))],f[cur][mask][j]);
				}
				if(((j>>1)&1)==1||n[i]=='1'){
					add(f[nxt][mask|1][j|(5*(n[i]=='1'))],f[cur][mask][j]);
				}
				if((j&1)==1||n[i]=='1'){
					add(f[nxt][mask|2][j|(6*(n[i]=='1'))],f[cur][mask][j]);
				}
				if((((j>>1)&1)==1&&((j>>2)&1)==1)||n[i]=='1'){
					add(f[nxt][mask|2][j|(1*(n[i]=='1'))],f[cur][mask][j]);
				}
				if(((j&1)==1&&((j>>2)&1)==1)||n[i]=='1'){
					add(f[nxt][mask|1][j|(2*(n[i]=='1'))],f[cur][mask][j]);
				}
				if(((j&1)==1&&((j>>1)&1)==1)||n[i]=='1'){
					add(f[nxt][mask|4][j|(4*(n[i]=='1'))],f[cur][mask][j]);
				}
				if(j==7||n[i]=='1'){
					add(f[nxt][mask][j],f[cur][mask][j]);
				}
			}
		}
		cur=nxt;
	}
	int ans=0;
	for(int i=0;i<8;i++){
		add(ans,f[cur][7][i]);
	}
	printf("%d\n",ans);
	return 0;
}