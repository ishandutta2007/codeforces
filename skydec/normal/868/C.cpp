#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int a[N];
int n,k;
bool hav[1<<4];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		rep(j,0,k-1){
			int x;scanf("%d",&x);
			if(!x)a[i]|=(1<<j);
		}
		hav[a[i]]=1;
	}
	rep(i,0,(1<<k)-1)rep(j,0,(1<<k)-1)if((i|j)==(1<<k)-1)if(hav[i]&&hav[j]){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}