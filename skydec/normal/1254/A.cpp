#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=105;
int n,m,k;
char s[N][N];
char res[N][N];
char kd(int x){
	if(x<=26)return x-1+'a';
	if(x<=52)return x-27+'A';
	return x-53+'0';
}
void Main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%s",s[i]+1);
	int all=0;
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='R')all++;
	int nk=1;
	int rst=all/k+(nk<=(all%k));
	rep(i,1,n){
		rep(jj,1,m){
			int j=jj;
			if(i&1)j=m+1-jj;
			if(s[i][j]=='.'){
				res[i][j]=kd(nk);
			}
			else{
				if(rst==0){
					nk++;
					rst=all/k+(nk<=(all%k));
				}
				rst--;
				res[i][j]=kd(nk);
			}
		}
	}
	rep(i,1,n){rep(j,1,m)printf("%c",res[i][j]);puts("");}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;	
}