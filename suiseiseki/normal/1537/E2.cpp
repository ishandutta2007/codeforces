#include <cstdio>
const int Maxn=500000;
int n,k;
char s[Maxn+5];
int nxt[Maxn+5],f[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	nxt[0]=0;
	f[0]=-1;
	for(int i=0,j=-1;i<n;i++){
		while(j>=0&&s[j]!=s[i]){
			j=f[j];
		}
		j++;
		f[i+1]=j;
		nxt[i+1]=nxt[f[i+1]];
		if(i+1<n&&s[nxt[i+1]]>=s[i+1]){
			nxt[i+1]=i+1;
		}
	}
	for(int i=1,j=0;i<=k;i++,j=nxt[j]+1){
		putchar(s[nxt[j]]);
	}
	putchar('\n');
	return 0;
}