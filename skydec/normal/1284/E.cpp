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
const int N=2600;
struct po{
	int x,y;
	inline po(int _x=0,int _y=0){
		x=_x;y=_y;
	}
	int dir(){
		if(x>=0&&y>=0)return 0;
		if(x<0&&y>=0)return 1;
		if(x<0&&y<0)return 2;
		return 3;
	}
};
po operator -(const po &a,const po &b){
	return po(a.x-b.x,a.y-b.y);
}
inline LL cross(const po &a,const po &b){
	return a.x*1ll*b.y-a.y*1ll*b.x;
}
bool operator <(po a,po b){
	if(a.dir()!=b.dir())return a.dir()<b.dir();
	return cross(a,b)>0;
}
int n;
po a[N];
LL ans=0;
LL C(int a,int b){
	if(a<b)return 0;
	LL res=1;
	rep(i,0,b-1)res=res*(a-i);
	rep(i,0,b-1)res=res/(i+1);
	return res;
}
po b[N*2];int m;
bool check(po a,po b){return cross(a,b)>=0;}
LL calc(int s){
	m=0;
	rep(i,1,n)if(s!=i)b[++m]=a[i]-a[s];
	sort(b+1,b+1+m);
	rep(i,1,m)b[i+m]=b[i];
	int j=1;
	LL ans=0;
	{
		rep(i,1,m){
			while(j<m+i-1&&check(b[i],b[j+1]))++j;
			ans=ans+C(min(j,i+m-1)-i,2);
		}
	}
	//printf("%d %lld\n",s,ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);

	rep(i,1,n)ans+=calc(i);
	ans=C(n,4)*4-ans;
	ans=ans*(n-4);
	printf("%lld\n",ans/2);
	assert(ans%2==0);
	return 0;
}