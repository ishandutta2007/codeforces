#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000006
using namespace std;
int n,f[N];
char S[N],T[N];
int main(){
	scanf("%d%s%s",&n,S+1,T+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(S[i]!=T[i]);
		if(S[i-1]==T[i]&&S[i]==T[i-1])
		f[i]=min(f[i],f[i-2]+1);
	}
	printf("%d",f[n]);
}