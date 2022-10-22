#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double ans;
struct node{
	double x,y;
}p[100010];
int stk[100010];
int size;
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
const double eps=1e-5;
double getX(int x){
	return p[x].x;
}
double getY(int x){
	return p[x].y;
}
long double getslope(int x,int y){
	return (fabs(getX(x)-getX(y))<eps?1e10:(getY(y)-getY(x))/(getX(y)-getX(x)));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].y-=p[i].x*p[i].x;
	}
	sort(p+1,p+n+1,cmp);
	int pos=0;p[0].x=-1e10;
	for(int i=1;i<=n;++i){
		if(fabs(p[i].x-p[pos].x)>eps) ++pos;p[pos]=p[i];
	}
	n=pos;
	if(pos==1){
		printf("0\n");return 0;
	}
//	for(int i=1;i<=n;++i) printf("%lf %lf\n",p[i].x,p[i].y);
	size=2;
	stk[1]=1,stk[2]=2;
	for(int i=3;i<=n;++i){
		while(size>1&&getslope(i,stk[size-1])>getslope(stk[size],stk[size-1])-eps) {
			--size;
		}
		stk[++size]=i;
	}
//	for(int i=1;i<=size;++i) printf("%d ",stk[i]);putchar('\n');
	printf("%d\n",size-1);
	return 0;
}