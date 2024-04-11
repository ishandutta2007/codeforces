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
const int N=110000;
int a[N],n;
int d[N],m;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n){
		int j=i;
		while(j<n&&a[j+1]==a[i])++j;
		d[++m]=j-i+1;
		i=j;
	}
	rep(i,1,m){
		if(d[i]%2==1){
			puts("Conan");
			return 0;
		}
	}
	puts("Agasa");
	return 0;
}