#include <cstdio>
#include <cstring>
#define Maxn 1000
#define Maxm 1000000
#define Mod 998244353
int b[Maxm+5];
int a[Maxn+5];
int le[Maxn+5],ri[Maxn+5];
int n,m;
int f[Maxn+5][Maxn+5];
int dfs(int left,int right){
	if(f[left][right]!=-1){
		return f[left][right];
	}
	if(right+1==left){
		return f[left][right]=1;
	}
	int p=left;
	for(int i=left+1;i<=right;i++){
		if(a[i]<a[p]){
			p=i;
		}
	}
	int l=le[a[p]],r=ri[a[p]];
	if(l<left||r>right){
		return f[left][right]=0;
	}
	int sum_1=0,sum_2=0;
	for(int i=left;i<=l;i++){
		sum_1+=1ll*dfs(left,i-1)*dfs(i,l-1)%Mod;
		sum_1%=Mod;
	}
	for(int i=r;i<=right;i++){
		sum_2+=1ll*dfs(r+1,i)*dfs(i+1,right)%Mod;
		sum_2%=Mod;
	}
	f[left][right]=1ll*sum_1*sum_2%Mod;
	int last=l;
	for(int i=l+1;i<=r;i++){
		if(a[i]==a[p]){
			f[left][right]=1ll*f[left][right]*dfs(last+1,i-1)%Mod;
			last=i;
		}
	}
	return f[left][right];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	int len=0;
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(j<=m&&b[j]==b[i]){
			j++;
		}
		j--;
		a[++len]=b[i];
	}
	m=len;
	if(m>(n<<1)){
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(le[a[i]]==0){
			le[a[i]]=i;
		}
		ri[a[i]]=i;
	}
	memset(f,-1,sizeof f);
	printf("%d\n",dfs(1,m));
	return 0;
}