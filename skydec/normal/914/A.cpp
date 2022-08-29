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
bool is(int x){
	rep(i,0,1000)if(i*i==x)return 1;
	return 0;
}
int main(){
	int n;scanf("%d",&n);
	int d=-10000000;
	while(n--){
		int x;scanf("%d",&x);
		if(!is(x))d=max(d,x);
	}		
	cout<<d<<endl;
	return 0;
}