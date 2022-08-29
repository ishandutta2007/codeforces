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
const int N=25;
string a[N],b[N];
int n,m;
int main(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	rep(i,1,m)cin>>b[i];
	int q;cin>>q;
	while(q--){
		int x;scanf("%d",&x);
		cout<<a[(x-1)%n+1]<<b[(x-1)%m+1]<<endl;
	}
	return 0;
}