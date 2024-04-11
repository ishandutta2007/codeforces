#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005;
typedef long long LL;
int n,a[N],tot,sum;
struct data{int s,id;} dat[N];
struct Ans{int x,y,s;} ans[N*5];
vector <data> vt0,vt1;

bool cmp(data a,data b)
{
	return a.s<b.s;
}

void ins(int x,int y,int s)
{
	ans[++tot]=(Ans){y,x,s};
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&dat[i].s),dat[i].id=i;
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	sort(dat+1,dat+1+n,cmp);
	rep(i,1,n) sum+=(dat[i].s-=a[i]);
	if(sum) return puts("NO"),0;
	rep(i,1,n)
	{
		data x=dat[i];
		if(x.s<0) vt1.pb(x);
		if(x.s>0)
		{
			while(vt1.size() && x.s)
			{
				if(-vt1.back().s<=x.s) ins(x.id,vt1.back().id,-vt1.back().s),x.s+=vt1.back().s,vt1.pop_back();
				else ins(x.id,vt1.back().id,x.s),vt1.back().s+=x.s,x.s=0;
			}
			if(x.s) return puts("NO"),0;
		}
	}
	if(vt1.size()==0)
	{
		puts("YES");
		printf("%d\n",tot);
		rep(i,1,tot) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].s);
	}
	else puts("NO");
	return 0;
}