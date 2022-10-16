#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

const int N=200005;
const int P=998244353;
const long long LIM=1500000ll*1500000;

inline long long dis(int x,int y){
	return (long long)x*x+(long long)y*y;
}

struct pos{
	int x,y,id;
	inline pos(){}
	inline pos(int _x,int _y){
		x=_x;
		y=_y;
	}
}a[N];

int n;
int res[N];

inline bool cmp(pos z,pos w){
	return dis(z.x,z.y)>dis(w.x,w.y);
}

inline unsigned _rand(unsigned p){
	static unsigned x=time(0);
	x^=x>>5;
	x^=x<<17;
	x^=x>>13;
	return x%p;
}

void init(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[i]=pos(x,y);
		a[i].id=i;
	}
	while(true){
		bool flag=true;
		random_shuffle(a+1,a+n+1,_rand);
		x=a[1].x,y=a[1].y;
		res[a[1].id]=1;
		for(int i=2;i<=n;i++){
			int qwq;
			if(dis(x+a[i].x,y+a[i].y)<dis(x-a[i].x,y-a[i].y)) qwq=1;
			else qwq=-1;
			if(qwq==1){
				x+=a[i].x;
				y+=a[i].y;
				res[a[i].id]=1;
			}
			else{
				x-=a[i].x;
				y-=a[i].y;
				res[a[i].id]=-1;
			}
		}
		if(dis(x,y)<=LIM){
			for(int i=1;i<=n;i++) printf("%d ",res[i]);
			return ;
		}
	}
}

int main(){
	srand(time(0));
	init();
	return 0;
}