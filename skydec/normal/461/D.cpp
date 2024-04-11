#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
const int P=1000000007;
struct UnionSystem{
	int n;
	int fa[N*2];
	string co;
	inline void set_string(string p){co=p;}
	inline void init(int _){
		n=_;
		for(int i=0;i<=n*2+1;i++)fa[i]=i;
	}
	int get(int x){
		if(x==fa[x])return x;
		return fa[x]=get(fa[x]);
	}
	inline void Union(int a,int b){
		a=get(a);b=get(b);if(a==b)return;fa[a]=b;
	}
	inline void deal(int l,int r,int x){
		//printf("_%d %d %d %s\n",l,r,x,co.c_str());
		if(x==0){
			Union((l-1)*2,r*2);
			Union((l-1)*2+1,r*2+1);
		}
		else{
			Union((l-1)*2,r*2+1);
			Union((l-1)*2+1,r*2);
		}
	}
	inline int calc(){
		for(int i=0;i<=n;i++)if(get(i*2)==get(i*2+1))return 0;
		int s=0;
		for(int i=0;i<=n*2+1;i++)if(get(i)==i)s++;
		s-=2;s/=2;
		int ans=1;
		for(int i=1;i<=s;i++)ans=ans*2ll%P;
		return ans;
	}
}odd,even;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	even.init((n+1)/2);
	odd.init(n/2);
	even.set_string("even");
	odd.set_string("odd");
	while(k--){
		int x,y;scanf("%d%d",&x,&y);char opt[3];scanf("%s",opt+1);
		int up=x+y-1;if(up>2*n-x-y+1)up=2*n-x-y+1;
		int down=1-x+y;if(down<x-y+1)down=x-y+1;
		if(down<=0)down=1;
		if(up>=n)up=n;
		if((x+y)&1)odd.deal((down+1)/2,(up+1)/2,opt[1]=='o');
		else even.deal((down+1)/2,(up+1)/2,opt[1]=='o');
	}
	printf("%d\n",odd.calc()*1ll*even.calc()%P);
}