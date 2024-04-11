#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ui;
const int N=2e3+2;
const ui p=1e9+7;
vector<int> lj[N];
ll a[N],l,r;
ui ans;
int b[N];
int n,i,x,y,d;
bool ed[N];
void inc(ui &x,ui y) {if ((x+=y)>=p) x-=p;}
ui dfs(int u)
{
	ed[u]=1;
	ui ans=1;
	for (auto v:lj[u]) if (a[v]>=l&&a[v]<r&&!ed[v]) ans=(ll)ans*dfs(v)%p;
	ed[u]=0;
	return ans+1;
}
int main()
{
	cin>>d>>n;
	for (i=1;i<=n;i++) cin>>b[i],a[i]=(ll)b[i]*N+i;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		lj[x].push_back(y);
		lj[y].push_back(x);
	}
	for (i=1;i<=n;i++) l=a[i],r=(ll)(b[i]+d+1)*N,inc(ans,dfs(i)-1);
	cout<<ans<<endl;
}