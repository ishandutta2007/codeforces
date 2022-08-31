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
bitset<7005>a[N];
int n,Q;
bitset<7005>gt[7005];
bitset<7005>sb[7005];
int mu[7005];
int getmu(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0){
		if((x/i)%i==0)return 0;
		x/=i;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&Q);
	rep(i,1,7000){
		int x=i;
		mu[i]=getmu(x);
		rep(j,1,7000/i){
			gt[i*j][i]=1;
		}
	}
	rep(i,1,7000)rep(j,1,7000/i)sb[i][i*j]=mu[j];

	while(Q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int x,v;
			scanf("%d%d",&x,&v);
			a[x]=gt[v];
		}
		if(ty==2){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]^a[z];
		}
		if(ty==3){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]&a[z];
		}
		if(ty==4){
			int x,v;scanf("%d%d",&x,&v);
			printf("%d",(int)((a[x]&sb[v]).count()%2));
		}
	}
	puts("");
	return 0;
}