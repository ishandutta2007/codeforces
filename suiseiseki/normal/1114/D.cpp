#include <cstdio>
#include <cstring>
#define Maxn 5000
struct Segment{
	int left,right;
	int c,las;
}seg[Maxn+5];
int c[Maxn+5];
int len;
int last[Maxn+5];
int f[Maxn+5][Maxn+5][2];
int mn(int a,int b){
	return a<b?a:b;
}
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1,j;i<=n;i=j){
		j=i;
		while(c[j]==c[i]){
			j++;
		}
		seg[++len].left=i;
		seg[len].right=j-1;
		seg[len].c=c[i];
		if(last[c[i]]!=0){
			seg[len].las=last[c[i]];
		}
		else{
			seg[len].las=0;
		}
		a[len]=c[i];
		last[c[i]]=len;
	}
	for(int k=2;k<=len;k++){
		for(int i=1;i+k-1<=len;i++){
			int j=i+k-1;
			f[i][j][0]=mn(mn(f[i+1][j][0]+(a[i]!=a[i+1]),f[i][j-1][0]+(a[i]!=a[j])),mn(f[i+1][j][1]+(a[i]!=a[j]),f[i][j-1][1]+(a[i]!=a[j-1])+(a[i]!=a[j])));

			f[i][j][1]=mn(mn(f[i+1][j][1]+(a[i]!=a[j]),f[i][j-1][1]+(a[j]!=a[j-1])),mn(f[i+1][j][0]+(a[i+1]!=a[j])+(a[i]!=a[j]),f[i][j-1][0]+(a[i]!=a[j])));
			if(a[i]==a[j]){
				f[i][j][1]=f[i][j][0]=mn(f[i+1][j-1][0]+(a[i]!=a[i+1]),f[i+1][j-1][1]+(a[i]!=a[j-1]));
			}
		}
	}
	printf("%d\n",mn(f[1][len][0],f[1][len][1]));
	return 0;
}