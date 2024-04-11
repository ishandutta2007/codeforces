#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 6
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k;
struct line
{
	int a,b,c;
	int num;
};
line l[MAXN];
bool covered[MAXN];
bool is_parallel(line &i,line &j)
{
	return 1LL*i.a*j.b==1LL*i.b*j.a;
}
pair<P,P> find_intersection(line &i,line &j)
{
	if(is_parallel(i,j)) return make_pair(P(-1,-1),P(-1,-1));
	ll px=1LL*i.b*j.c-1LL*j.b*i.c;
	ll qx=1LL*i.a*j.b-1LL*j.a*i.b;
	ll py=1LL*i.a*j.c-1LL*j.a*i.c;
	ll qy=-qx;
	ll g=__gcd(px,qx); px/=g; qx/=g;
	g=__gcd(py,qy); py/=g; qy/=g;
	if(px<0) {px=-px; qx=-qx;} if(px==0&&qx<0) qx=-qx;
	if(py<0) {py=-py; qy=-qy;} if(py==0&&qy<0) qy=-qy;
	return make_pair(P(px,qx),P(py,qy));
}
vector<pair<int,int> > ans;
void solve(vector<line> &v,int k)
{
	if(k==0&&v.size()>0) return;
	if(v.size()==0)
	{
		puts("YES");
		printf("%d\n",(int)ans.size());
		for(auto p:ans) printf("%d %d\n",p.F,p.S);
		exit(0);
	}
	if(v.size()<=k)
	{
		for(auto l:v) ans.push_back(P(l.num,-1));
		puts("YES");
		printf("%d\n",(int)ans.size());
		for(auto p:ans) printf("%d %d\n",p.F,p.S);
		exit(0);
	}
	if(v.size()>k*k)
	{
		P chosen=P(-1,-1);
		for(int i=0;i<k*k+1;i++)
		{
			if(chosen.F!=-1) break;
			for(int j=i+1;j<k*k+1;j++)
			{
				if(is_parallel(v[i],v[j])) continue;
				auto points=find_intersection(v[i],v[j]);
				int cnt=2;
				for(int l=0;l<k*k+1;l++)
				{
					if(l==i||l==j) continue;
					if(is_parallel(v[i],v[l])) continue;
					auto points2=find_intersection(v[i],v[l]);
					if(points==points2) cnt++;
					if(cnt>=k+1) break;
				}
				if(cnt>=k+1) 
				{
					chosen=P(i,j);
					break;
				}
			}
		}
		if(chosen.F==-1) return;
		vector<line> tmp;
		auto points=find_intersection(v[chosen.F],v[chosen.S]);
		for(int i=0;i<(int)v.size();i++)
		{
			if(i==chosen.F||i==chosen.S) continue;
			if(!is_parallel(v[chosen.F],v[i])&&find_intersection(v[chosen.F],v[i])==points) continue;
			tmp.push_back(v[i]); 
		}
		ans.push_back(P(v[chosen.F].num,v[chosen.S].num));
		solve(tmp,k-1);
		ans.pop_back();
		return;
	}
	for(int i=0;i<k+1;i++)
	{
		for(int j=i+1;j<k+1;j++)
		{
			if(is_parallel(v[i],v[j])) continue;
			auto points=find_intersection(v[i],v[j]);
			vector<line> tmp;
			for(int l=0;l<v.size();l++)
			{
				if(l==i||l==j) continue;
				if(is_parallel(v[i],v[l])&&find_intersection(v[i],v[l])==points) continue;
				tmp.push_back(v[l]);
			}
			ans.push_back(P(v[i].num,v[j].num));
			solve(tmp,k-1);
			ans.pop_back();
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
		l[i].num=i;
	}
	vector<line> v;
	for(int i=1;i<=n;i++) v.push_back(l[i]);
	solve(v,k);
	puts("NO");
	return 0;
}