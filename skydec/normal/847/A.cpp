#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=105;
int l[N],r[N];
pii a[N];
int m;
int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	rep(i,1,n){
		if(!l[i]){
			int x=i;
			while(r[x])x=r[x];
			a[++m]=pii(i,x);
		}
	}
	rep(i,1,m-1){
		r[a[i].se]=a[i+1].fi;
		l[a[i+1].fi]=a[i].se;
	}
	rep(i,1,n)printf("%d %d\n",l[i],r[i]);
	return 0;
}