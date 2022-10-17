#include <cstdio>
#include <iostream>
using namespace std;
#define Mod 1000000007
#define ll long long
int add(int a,int b){
	a+=b;
	if(a>Mod){
		a-=Mod;
	}
	if(a<0){
		a+=Mod;
	}
	return a;
}
int mul(int a,int b){
	return (int)((ll)a*b%Mod);
}
int a[105][105];
int ans[105][105];
int b[105][105];
ll n;
int m;
void multi_a(){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			b[i][j]=a[i][j];
			a[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		for(int k=0;k<m;k++){
			for(int j=0;j<m;j++){
				a[i][j]=add(a[i][j],mul(b[i][k],b[k][j]));
			}
		}
	}
}
void multi_ans(){
	for(int i=0;i<m;i++){
		for(int j=0;j<1;j++){
			b[i][j]=ans[i][j];
			ans[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		for(int k=0;k<m;k++){
			for(int j=0;j<1;j++){
				ans[i][j]=add(ans[i][j],mul(a[i][k],b[k][j]));
			}
		}
	}
}
int main(){
	cin>>n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		ans[i][0]=1;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j-1==i){
				a[i][j]=1;
			}
		}
	}
	a[m-1][0]=1;
	a[m-1][m-1]=1;
	n-=m-1;
	while(n>0){
		if(n&1){
			multi_ans();
		}
		n>>=1;
		multi_a();
	}
	printf("%d\n",ans[m-1][0]);
	return 0;
}