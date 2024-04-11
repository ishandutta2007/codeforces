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
const int N=16;
int a[N];
int n;
int main(){
	scanf("%d",&n);
	rep(i,0,n-1)scanf("%d",&a[i]);
	rep(S,0,(1<<n)-1){
		int w=0;
		rep(i,0,n-1)if(S&(1<<i))w+=a[i];
		else w-=a[i];
		w=(w%360+360)%360;
		if(w==0){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}