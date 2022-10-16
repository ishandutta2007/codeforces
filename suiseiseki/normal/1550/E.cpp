#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=200000;
const int Maxk=17;
int n,k;
char s[Maxn+5];
int val[Maxn+5];
int f[1<<Maxk|5];
int g[Maxn+5][Maxk+5];
bool check(int len){
	memset(f,0x3f,sizeof f);
	int mask=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(val[i]==-1){
			continue;
		}
		while(j<=n&&val[j]==val[i]){
			j++;
		}
		j--;
		if(j-i+1>=len){
			mask|=(1<<val[i]);
		}
	}
	for(int i=0;i<k;i++){
		int pos_l=1,pos_r=0;
		for(int j=1;j<=n;j++){
			pos_l=std::max(pos_l,j);
			while(pos_r<=n&&pos_r-pos_l+1<len){
				pos_r++;
				if(val[pos_r]!=i&&val[pos_r]!=-1){
					pos_l=pos_r+1;
				}
			}
			g[j][i]=pos_r;
		}
		g[n+1][i]=n+1;
	}
	f[mask]=0;
	for(int i=0;i<(1<<k);i++){
		if(f[i]>n){
			continue;
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				continue;
			}
			f[i|(1<<j)]=std::min(f[i|(1<<j)],g[f[i]+1][j]);
		}
	}
	return f[(1<<k)-1]<=n;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		val[i]=s[i]-'a';
		if(s[i]=='?'){
			val[i]=-1;
		}
	}
	int left=0,right=n/k;
	while(left<right){
		int mid=(left+right+1)>>1;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	printf("%d\n",left);
	return 0;
}