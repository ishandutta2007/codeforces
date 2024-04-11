#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int m,n;
char s[65][1015];
long long a[1015],b[1015],c[1015][1015];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)a[i]=a[i]*2+s[j][i]-'0';
	}
	sort(a,a+m);
	for(int i=0;i<=m;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	b[0]=b[1]=1;
	for(int i=2;i<=m;i++){
		for(int j=0;j<i;j++)b[i]=(b[i]+c[i-1][j]*b[j])%M;
	}
	int ans=1;
	for(int i=0,j=0;i<m;i=j){
		for(;j<m&&a[j]==a[i];j++);
		int k=j-i;
		ans=ans*b[k]%M;
	}
	printf("%d\n",ans);
	return 0;
}