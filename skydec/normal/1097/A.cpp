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
char s[9][5];
int main(){
	rep(i,0,5)scanf("%s",s[i]);
	rep(i,1,5)if(s[i][0]==s[0][0]||s[i][1]==s[0][1]){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}