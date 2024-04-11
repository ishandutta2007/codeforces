#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=30;
int n,a;
struct data{int a,id;} dat[N];		

bool cmp_a(data a,data b)
{
	return a.a<b.a;
}

bool cmp_id(data a,data b)
{
	return a.id<b.id;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&dat[i].a),dat[i].id=i;
	sort(dat+1,dat+1+n,cmp_a),a=dat[n].a;
	repd(i,n,1) dat[i].a=dat[i-1].a;
	dat[1].a=a;
	sort(dat+1,dat+1+n,cmp_id);
	rep(i,1,n-1) printf("%d ",dat[i].a);
	printf("%d\n",dat[n].a);
	return 0;
}