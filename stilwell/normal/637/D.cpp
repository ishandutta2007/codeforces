#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
int n,m,s,d;
int a[N];
int ans[N<<2][2];
int top=0;
void wei(){
	printf("IMPOSSIBLE");
	exit(0);
}
void run(int x){
	if(!x)return;
	++top;ans[top][0]=1;
	ans[top][1]=x;
}
void jump(int x){
	++top;ans[top][0]=0;
	ans[top][1]=x;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&d);
	rep(i,1,n)scanf("%d",&a[i]);
	if(d==1)wei();
	sort(a+1,a+1+n);
	int pos=0;
	int R=0;
	if(a[1]-1<s)wei();
	pos=a[1]+1;
	R=d-2;
	run(a[1]-1);
	rep(i,2,n){
		if(a[i]-1-pos>=s){
			jump(d-R);
			run(a[i]-1-pos);
			pos=a[i]+1;
			R=d-2;
		}
		else{
			if(a[i]+1-pos>R)wei();
			R-=a[i]+1-pos;
			pos=a[i]+1;
		}
	}
	if(R!=d)jump(d-R);
	run(m-pos);
	rep(i,1,top){
		if(ans[i][0])printf("RUN %d\n",ans[i][1]);
		else printf("JUMP %d\n",ans[i][1]);
	}
	return 0;
}