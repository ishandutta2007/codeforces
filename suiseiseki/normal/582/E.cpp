#include <cstdio>
const int Maxn=500;
const int Maxm=(1<<16);
const int Mod=1000000007;
int n,m;
char s[Maxn+5];
int f[Maxn+5][Maxm+5];
int lson[Maxn+5],rson[Maxn+5],id_tot;
int g[9][Maxm+5];
void init(){
	for(int i=0;i<4;i++){
		int t=0;
		for(int j=0;j<16;j++){
			t|=(((j>>i)&1)<<j);
		}
		g[i][t]++;
		g[i+4][(Maxm-1)^t]++;
		g[8][t]++;
		g[8][(Maxm-1)^t]++;
	}
}
void FWT_or(int *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				if(flag==1){
					a[i+j+k]=(a[i+j+k]+a[j+k])%Mod;
				}
				else{
					a[i+j+k]=(a[i+j+k]-a[j+k]+Mod)%Mod;
				}
			}
		}
	}
}
void FWT_and(int *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				if(flag==1){
					a[j+k]=(a[i+j+k]+a[j+k])%Mod;
				}
				else{
					a[j+k]=(a[j+k]-a[i+j+k]+Mod)%Mod;
				}
			}
		}
	}
}
void merge_or(int *a,int *b,int len){
	static int c[Maxm+5];
	for(int i=0;i<len;i++){
		c[i]=b[i];
	}
	FWT_or(a,1,len);
	FWT_or(c,1,len);
	for(int i=0;i<len;i++){
		a[i]=1ll*a[i]*c[i]%Mod;
	}
	FWT_or(a,-1,len);
}
void merge_and(int *a,int *b,int len){
	static int c[Maxm+5];
	for(int i=0;i<len;i++){
		c[i]=b[i];
	}
	FWT_and(a,1,len);
	FWT_and(c,1,len);
	for(int i=0;i<len;i++){
		a[i]=1ll*a[i]*c[i]%Mod;
	}
	FWT_and(a,-1,len);
}
void work_dfs(int &u,int left,int right){
	static int d[Maxm+5];
	if(left==right){
		u=++id_tot;
		int pos;
		if(s[left]=='?'){
			pos=8;
		}
		else if(s[left]>='A'&&s[left]<='Z'){
			pos=s[left]-'A';
		}
		else{
			pos=s[left]-'a'+4;
		}
		for(int i=0;i<Maxm;i++){
			f[u][i]=g[pos][i];
		}
		return;
	}
	int num=0,mid=-1;
	for(int i=left;i<=right;i++){
		if(s[i]=='('){
			num++;
		}
		if(s[i]==')'){
			num--;
		}
		if(num==0&&(s[i]!='('&&s[i]!=')')){
			mid=i;
			break;
		}
	}
	if(mid==-1){
		work_dfs(u,left+1,right-1);
		return;
	}
	u=++id_tot;
	work_dfs(lson[u],left,mid-1);
	work_dfs(rson[u],mid+1,right);
	if(s[mid]=='|'){
		for(int i=0;i<Maxm;i++){
			f[u][i]=f[lson[u]][i];
		}
		merge_or(f[u],f[rson[u]],Maxm);
	}
	else if(s[mid]=='&'){
		for(int i=0;i<Maxm;i++){
			f[u][i]=f[lson[u]][i];
		}
		merge_and(f[u],f[rson[u]],Maxm);
	}
	else{
		for(int i=0;i<Maxm;i++){
			f[u][i]=f[lson[u]][i];
		}
		merge_or(f[u],f[rson[u]],Maxm);
		for(int i=0;i<Maxm;i++){
			d[i]=f[u][i];
		}
		for(int i=0;i<Maxm;i++){
			f[u][i]=f[lson[u]][i];
		}
		merge_and(f[u],f[rson[u]],Maxm);
		for(int i=0;i<Maxm;i++){
			f[u][i]=(f[u][i]+d[i])%Mod;
		}
	}
}
int a[Maxm+5],b[Maxm+5];
int main(){
	init();
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	int root=0;
	work_dfs(root,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int mask=0;
		for(int j=0;j<4;j++){
			int x;
			scanf("%d",&x);
			mask|=(x<<j);
		}
		a[i]=mask;
		scanf("%d",&b[i]);
	}
	int ans=0;
	for(int mask=0;mask<Maxm;mask++){
		bool flag=1;
		for(int i=1;i<=m;i++){
			if(((mask>>a[i])&1)!=b[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			ans=(ans+f[root][mask])%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}