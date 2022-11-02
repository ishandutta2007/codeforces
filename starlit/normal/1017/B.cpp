#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int n,d[2],d1[2];
char S[N],T[N];
long long ans;
int main(){
	scanf("%d%s%s",&n,S,T);
	for(int i=0;i<n;i++){
		d[S[i]-'0']++;
		if(T[i]=='1')d1[S[i]-'0']++;
	}
	ans=1ll*d[0]*(d[0]-1)/2+1ll*d[1]*(d[1]-1)/2+1ll*d1[0]*d1[1];
	printf("%I64d",1ll*n*(n-1)/2-ans);
}