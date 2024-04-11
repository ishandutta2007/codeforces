#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
int k,m;
const int fix=100000;
vector<int> way[210000];
map<int,bool>cz[210000];
set<int>ans;
int now;
inline void ha(int x){
	if(!cz[x+fix][now])
	way[x+fix].pb(now),cz[x+fix][now]=1;
}
void go2(int a,int b){
	ha(a-b);
	ha(a+b);
	ha(-a+b);
	ha(-a-b);
	ha(a*b);
	ha(-a*b);
}
void go3(int a,int b,int c){
	go2(a+b,c);
	go2(a,b+c);
	go2(a-b,c);
	go2(a,b-c);
	go2(a*b,c);
	go2(a,b*c);
}
void go4(int a,int b,int c,int d){
	go3(a,(b+c),d);
	go3((a+b),c,d);
	go3(a,b,c+d);
	go3(a*10+b,c,d);
	go3(a,b*10+c,d);
	go3(a,b,c*10+d);
	go3(a,b-c,d);
	go3(a-b,c,d);
	go3(a,b,c-d);
	go2(a*100+b*10+c,d);
	go2(a,b*100+c*10+d);
	ha(a*1000+b*100+c*10+d);
	go3(a*b,c,d);
	go3(a,b*c,d);
	go3(a,b,c*d);
}
inline void outer(){
	for(it i=ans.begin();i!=ans.end();++i){
		int x=*i;
		if(x<10000000)printf("0");
		if(x<1000000)printf("0");
		if(x<100000)printf("0");
		if(x<10000)printf("0");
		if(x<1000)printf("0");
		if(x<100)printf("0");
		if(x<10)printf("0");
		printf("%d\n",x);
	}
}
int main(){
	scanf("%d%d",&k,&m);
	rep(i,0,9999){
		int a=i/1000;
		int b=(i/100)%10;
		int c=(i/10)%10;
		int d=i%10;
		now=i;
		go4(a,b,c,d);
	}
	rep(i,-20000,20000){
		rep(j,0,way[i+fix].size()-1)
		rep(kp,0,way[k-i+fix].size()-1){
			ans.insert(way[i+fix][j]*10000+way[k-i+fix][kp]);
			if(ans.size()>=m)goto should;
		}
	}
	rep(i,-20000,20000){
		rep(j,0,way[i+fix].size()-1)
		rep(kp,0,way[k+i+fix].size()-1){
			ans.insert(way[i+fix][j]*10000+way[k+i+fix][kp]);
			if(ans.size()>=m)goto should;
		}
	}
	should:;
	outer();
	return 0;
}