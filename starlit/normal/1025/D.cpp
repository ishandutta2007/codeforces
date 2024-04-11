#include<iostream>
#include<cstdio>
#include<cstring>
#define N 707
#define rg register int
using namespace std;
int n,a[N];
inline int gcd(int x,int y){
	for(;y;swap(x,y),y%=x);
	return x;
}
bool f[N][N],g[N][N],mp[N][N];
int main(){
	scanf("%d",&n);
	for(rg i=1,j;i<=n;i++){
		scanf("%d",a+i);
		f[i][i]=g[i][i]=1;
        for(j=1;j<i;j++)
		mp[j][i]=gcd(a[i],a[j])>1;
	}
    for(rg ln=1,i,j,k;ln<n;ln++)
	for(i=1;i<=n;i++){
        if((j=i-ln)>0)
		for(k=j;k<i;k++)
		if(mp[k][i]&&f[j][k]&&g[k][i-1]){
			f[j][i]=1;break;
		}
        if((j=i+ln)<=n)
		for(k=i+1;k<=j;k++)
		if(mp[i][k]&&f[i+1][k]&&g[k][j]){
			g[i][j]=1;break;
		}
	}
    for(rg i=1;i<=n;i++)
	if(f[1][i]&&g[i][n])return puts("Yes"),0;
	puts("No");
}