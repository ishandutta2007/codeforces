#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005;
int ans,n,_;
bool f[20][20];
char a[N],b[N];

void solve()
{
	scanf("%d",&n);
	scanf("%s",a+1),scanf("%s",b+1);
	rep(i,1,n) if(a[i]>b[i]) {puts("-1"); return;}
	rep(i,0,19) rep(j,0,19) f[i][j]=0;
	rep(i,1,n) f[a[i]-'a'][b[i]-'a']=1;
	ans=0;
	rep(i,0,18)
	{
		int p=-1;
		rep(j,i+1,19) if(f[i][j]) {p=j; break;}
		if(p==-1) continue;
		++ans;
		rep(j,0,19) f[p][j]|=f[i][j];
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}