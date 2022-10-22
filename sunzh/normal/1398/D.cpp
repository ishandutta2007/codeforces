#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int R,G,B;
int ans; 
int a[210],b[210],c[210];
int f[210][210][210];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	R=read(),G=read(),B=read();
	for(int i=1;i<=R;++i) a[i]=read();
	for(int i=1;i<=G;++i) b[i]=read();
	for(int i=1;i<=B;++i) c[i]=read();
	sort(a+1,a+R+1);sort(b+1,b+G+1);sort(c+1,c+B+1);
	for(int i=0;i<=R;++i)
		for(int j=0;j<=G;++j)
			for(int k=0;k<=B;++k){
				if(i&&j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]*b[j]);
				if(i&&k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i]*c[k]);
				if(j&&k) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+b[j]*c[k]);
				ans=max(ans,f[i][j][k]);
			}
	printf("%d\n",ans);
	return 0;
}