#include<cstdio>
#include<cstring>
const int N=1000005,M=5000005;
int n,r,c,p[N],nxt[N],f[N],ret[N];
char s[N+M];
int main(){
	scanf("%d%d%d",&n,&r,&c);
	for(int i=1,j=0;i<=n;i++){
		scanf("%s",s+j);
		j+=strlen(s+j);
		s[j++]=' ';
		p[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j<=n&&p[j]-p[i-1]-1<=c)j++;
		nxt[i]=j;
	}
	nxt[n+1]=n+1;
	for(int i=1;i<=n+1;i++)ret[i]=i,f[i]=nxt[i];
	for(int b=r;b;b>>=1){
		if(b&1)for(int i=1;i<=n;i++)ret[i]=f[ret[i]];
		for(int i=1;i<=n;i++)f[i]=f[f[i]];
	}
	int q=1;
	for(int i=2;i<=n;i++)if(ret[i]-i>ret[q]-q)q=i;
	for(int i=0;i<r;i++){
		for(int j=p[q-1];j<p[nxt[q]-1]-1;j++)putchar(s[j]);
		q=nxt[q];
		puts("");
	}
}