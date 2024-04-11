#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x[3],y[3],xmid,ymid;
vector<int> vx,vy;
vector<pair<P,P> > ans;
int main()
{
	for(int i=0;i<3;i++) 
	{
		scanf("%d%d",&x[i],&y[i]);
		vx.push_back(x[i]); vy.push_back(y[i]);
	}
	sort(vx.begin(),vx.end()); sort(vy.begin(),vy.end());
	xmid=vx[1]; ymid=vy[1];
	for(int i=0;i<3;i++)
	{
		ans.push_back(make_pair(P(xmid,ymid),P(x[i],ymid)));
		ans.push_back(make_pair(P(x[i],ymid),P(x[i],y[i])));
	}
	printf("%d\n",(int)ans.size());
	for(auto p:ans) printf("%d %d %d %d\n",p.F.F,p.F.S,p.S.F,p.S.S);
	return 0;
}