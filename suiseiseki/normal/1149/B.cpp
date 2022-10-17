#include <cstdio>
#define Maxn 100000
char a[5][Maxn+5];
int len[5];
char s[Maxn+5];
int nxt[Maxn+5][30];
int f[255][255][255];
char qu[3];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,q,x;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=0;i<26;i++){
		nxt[n][i]=nxt[n+1][i]=n+1;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++){
			if(s[i+1]==(char)(j+'a')){
				nxt[i][j]=i+1;
			}
			else{
				nxt[i][j]=nxt[i+1][j];
			}
		}
	}
	while(q--){
		scanf("%s",qu);
		if((*qu)=='+'){
			scanf("%d",&x);
			scanf("%s",qu);
			a[x][++len[x]]=(*qu);
			if(x==1){
				for(int i=0;i<=len[2];i++){
					for(int j=0;j<=len[3];j++){
						f[len[1]][i][j]=nxt[f[len[1]-1][i][j]][(*qu)-'a'];
						if(i>0){
							f[len[1]][i][j]=mn(f[len[1]][i][j],nxt[f[len[1]][i-1][j]][a[2][i]-'a']);
						}
						if(j>0){
							f[len[1]][i][j]=mn(f[len[1]][i][j],nxt[f[len[1]][i][j-1]][a[3][j]-'a']);
						}
					}
				}
			}
			else if(x==2){
				for(int i=0;i<=len[1];i++){
					for(int j=0;j<=len[3];j++){
						f[i][len[2]][j]=nxt[f[i][len[2]-1][j]][(*qu)-'a'];
						if(i>0){
							f[i][len[2]][j]=mn(f[i][len[2]][j],nxt[f[i-1][len[2]][j]][a[1][i]-'a']);
						}
						if(j>0){
							f[i][len[2]][j]=mn(f[i][len[2]][j],nxt[f[i][len[2]][j-1]][a[3][j]-'a']);
						}
					}
				}
			}
			else{
				for(int i=0;i<=len[1];i++){
					for(int j=0;j<=len[2];j++){
						f[i][j][len[3]]=nxt[f[i][j][len[3]-1]][(*qu)-'a'];
						if(i>0){
							f[i][j][len[3]]=mn(f[i][j][len[3]],nxt[f[i-1][j][len[3]]][a[1][i]-'a']);
						}
						if(j>0){
							f[i][j][len[3]]=mn(f[i][j][len[3]],nxt[f[i][j-1][len[3]]][a[2][j]-'a']);
						}
					}
				}
			}
			if(f[len[1]][len[2]][len[3]]<=n){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
		else{
			scanf("%d",&x);
			len[x]--;
			if(f[len[1]][len[2]][len[3]]<=n){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}