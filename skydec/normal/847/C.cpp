#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=310000;
int n;LL k;
int dep[N];
char ans[N*2];
int t;
int go(int x,int st){
	if(!dep[x])return st;
	rep(i,1,dep[x]-1){
		ans[st]='(';
		++st;
		ans[st]=')';
		++st;
	}
	ans[st]='(';
	++st;
	int ed=go(x+1,st);
	ans[ed]=')';
	return ed+1;
}
void outit(){
	int aa=0;
	rep(i,0,n)aa+=dep[i];
	dep[0]+=n-aa;
	int gt=go(0,1);
	rep(i,1,2*n)putchar(ans[i]);
	puts("");
}
int main(){
	scanf("%d%lld",&n,&k);
	rep(d,0,n-1)if(d*1ll*(d+1)/2<=k){
		if((d*1ll*(d+1)/2)+(n-1-d)*1ll*d<k)continue;
		rep(i,0,d)dep[i]++;
		LL rest=k-(d*1ll*(d+1)/2);
		per(i,d,1){
			while(rest>=i){
				rest-=i;
				dep[i]++;
			}
		}
		outit();
		return 0;
	}
	printf("Impossible\n");
	return 0;
}