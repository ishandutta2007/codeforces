#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=1005;
char a[N];
int n;
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	rep(i,1,n)printf("%c",a[i]);
	per(i,n,1)printf("%c",a[i]);
	putchar('\n');
	return 0;
}