#include<cstdio>
#include<cstring>
using namespace std;
int T,n,mp[200],cnt,a[10][99][2],f[99][1<<10],lst1[99][1<<10],lst2[99][1<<10],z[10][999],nxt[10][999][99],ans,I,J;
bool vis[99][1<<10];char s[10][999],pm[99];
void calc(int i,int j){
	if(vis[j][i]) return;
	f[j][i]=vis[j][i]=1;
	for(int k=0;k<n;++k) if(a[k][j][(i>>k)&1]<0){f[j][i]=0;return;}
	for(int k=1,msk,flg;k<=cnt;++k){
		msk=flg=0;
		for(int $=0,_;$<n;++$)
			if((_=nxt[$][a[$][j][(i>>$)&1]][k])+1) msk|=(z[$][_]<<$);
			else{flg=1;break;}
		if(flg) continue;
		calc(msk,k);
		if(f[k][msk]>=f[j][i]) f[j][i]=f[k][msk]+1,lst1[j][i]=k,lst2[j][i]=msk;
	}
	if(f[j][i]>ans) ans=f[j][i],I=j,J=i;
}
int main(){
	for(int i='a';i<='z';++i) pm[mp[i]=++cnt]=i;
	for(int i='A';i<='Z';++i) pm[mp[i]=++cnt]=i;
	for(scanf("%d",&T);T--;putchar('\n'),ans=0){
		scanf("%d",&n);
		for(int i=0;i<n;++i) for(int j=1;j<=cnt;++j) a[i][j][0]=a[i][j][1]=-1;
		for(int i=0,len;i<n;++i){
			scanf("%s",s[i]);len=strlen(s[i]);
			for(int j=0;j<len;++j)
				if(a[i][s[i][j]=mp[s[i][j]]][0]+1) z[i][a[i][s[i][j]][1]=j]=1;
				else z[i][a[i][s[i][j]][0]=j]=0;
			for(int j=1;j<=cnt;++j) nxt[i][len-1][j]=-1;
			for(int j=len-1;j;nxt[i][j-1][s[i][j]]=j,--j)
				for(int k=1;k<=cnt;++k) nxt[i][j-1][k]=nxt[i][j][k];
		}
		for(int i=1;i<=cnt;++i) for(int j=0;j<(1<<n);++j) vis[i][j]=0;
		for(int i=(1<<n)-1;i+1;--i) for(int j=1;j<=cnt;++j) calc(i,j);
		printf("%d\n",ans);
		for(int t1,t2;ans--;I=t1,J=t2) putchar(pm[I]),t1=lst1[I][J],t2=lst2[I][J];
	}
	return 0;
}