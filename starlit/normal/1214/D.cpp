#include<bits/stdc++.h>
const int N=1000006,M1=998244353,M2=1000000007;
using namespace std;
int n,m,x,l1[N],l2[N],r1[N],r2[N];
bool mp[N];
char S[N];
int main(){
	scanf("%d%d",&n,&m);
	l1[0]=l2[0]=1,r1[n*m-1]=r2[n*m-1]=1;
	for(int i=0;i<n;i++){
		scanf("%s",S);
		for(int j=0;j<m;j++)
		if(mp[x=i*m+j]=S[j]=='.'){
			if(i)l1[x]=l1[x-m],
			l2[x]=l2[x-m];
			if(j)l1[x]=(l1[x]+l1[x-1])%M1,
			l2[x]=(l2[x]+l2[x-1])%M2;
		}
	}
	for(int i=n-1;~i;i--)
	for(int j=m-1;~j;j--)
	if(mp[x=i*m+j]){
		if(i<n-1)r1[x]=r1[x+m],
		r2[x]=r2[x+m];
		if(j<m-1)r1[x]=(r1[x]+r1[x+1])%M1,
		r2[x]=(r2[x]+r2[x+1])%M2;
	}
	if(r1[0]==0&&r2[0]==0)
	return puts("0"),0;
	for(int i=1;i<n*m-1;i++)
	if(1ll*l1[i]*r1[i]%M1==r1[0]&&
	1ll*l2[i]*r2[i]%M2==r2[0]){
		//cerr<<i<<":"<<l1[i]<<' '<<r1[i]<<' '<<r1[0]<<endl;
	return puts("1"),0;
	}
	puts("2");
}/*
4 7
.......
..###..
.....#.
.......
*/