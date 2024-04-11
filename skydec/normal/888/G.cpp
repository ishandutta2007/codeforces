#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=210000;
int go[N*32][2];
int tot;
int n,a[N];
void inittrie(){
	rep(i,1,tot){
		go[i][0]=go[i][1]=0;
	}
	tot=1;
}
void ins(int x){
	int now=1;
	per(i,29,0){
		int w=((x&(1<<i))>0);
		if(!go[now][w]){
			go[now][w]=++tot;
		}
		now=go[now][w];
	}
}
int ask(int x){
	int now=1;
	int ans=0;
	per(i,29,0){
		int w=((x&(1<<i))>0);
		if(go[now][w])now=go[now][w];
		else now=go[now][w^1],ans+=(1<<i);
	}
	return ans;
}
LL work(int l,int r,int b){
	if(b==-1)return 0;
	sort(a+l,a+r+1);
	if(!(a[r]&(1<<b)))return work(l,r,b-1);
	if(a[l]&(1<<b))return work(l,r,b-1);
	LL ans=1ll<<60;
	inittrie();
	int mid=0;
	rep(i,l,r)if(!(a[i]&(1<<b)))ins(a[i]),mid=i;
	rep(i,l,r)if(a[i]&(1<<b))ans=min(ans,ask(a[i])*1ll);
	rep(i,l,r)a[i]&=((1<<b)-1);	
	return ans+work(l,mid,b-1)+work(mid+1,r,b-1);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	printf("%lld\n",work(1,n,29));
	return 0;
}