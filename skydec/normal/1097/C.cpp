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
const int N=110000;
int sn,n;
int w[N];
char s[N*5];
bool check(int &x){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int w=0;
	rep(i,1,n)if(s[i]=='(')++w;
	else{
		--w;
		if(w<0)break;
	}

	if(w>=0){
		x=w;
		return 1;
	}

	w=0;
	per(i,n,1)if(s[i]==')'){
		--w;
	}
	else{
		++w;
		if(w>0)break;
	}

	if(w<=0){
		x=w;
		return 1;
	}
	return 0;
}
map<int,int>na;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		if(check(w[sn+1]))++sn;
	}
	rep(i,1,sn)na[w[i]]++;
	int ans=0;
	rep(i,1,500000)ans+=min(na[i],na[-i]);
	ans+=na[0]/2;
	printf("%d\n",ans);
	return 0;
}