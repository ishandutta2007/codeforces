#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5000
using namespace std;
int n,m,q,x,y,cnts[N],val[20],vv[N],cntt[N][102];
char S[20];
inline int rd(){
	int res=0;
	scanf("%s",S);
	for(int i=0;i<n;i++)res=res<<1|(S[i]-'0');
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=n-1;i>=0;i--)
	scanf("%d",val+i);
	for(;m--;)x=rd(),cnts[x]++;
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)
		if(i>>j&1^1)vv[i]+=val[j];
	}
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<1<<n;j++)
		if(vv[j]<101)cntt[i][vv[j]]+=cnts[i^j];
		for(int j=1;j<101;j++)cntt[i][j]+=cntt[i][j-1];
	}
	for(int i=0;i<q;i++){
		x=rd(),scanf("%d",&y);
		printf("%d\n",cntt[x][y]);
	}
}
/*
2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60
*/