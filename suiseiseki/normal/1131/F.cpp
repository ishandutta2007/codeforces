#include <cstdio>
#define Maxn 150000
int x[Maxn+5],y[Maxn+5];
int left[Maxn+5],right[Maxn+5];
int f[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	left[l[fa_x]]=r[fa_y];
	right[r[fa_y]]=l[fa_x];
	f[fa_y]=fa_x;
	l[fa_x]=l[fa_y];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i]=i;
		l[i]=r[i]=i;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		merge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++){
		if(left[i]==0){
			for(int j=i;j;j=right[j]){
				printf("%d ",j);
			}
			puts("");
			break;
		}
	}
	return 0;
}
///////////////