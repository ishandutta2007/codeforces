#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.5e5+2,p=998244353;
ll mi[N];
int sol2(vector<int> &a,vector<int> &b,int o,int x)
{
	if (!a.size()||!b.size()||o==-1) return mi[a.size()+b.size()];
	vector<int> c[2],d[2];
	for (int x:a) c[x>>o&1].push_back(x);
	for (int x:b) d[x>>o&1].push_back(x);
	if (x>>o&1) {x^=1<<o;return ((ll)(sol2(c[0],d[1],o-1,x)+1)*(sol2(c[1],d[0],o-1,x)+1)+p-1)%p;}
	return (sol2(c[0],d[0],o-1,x)+sol2(c[1],d[1],o-1,x)+mi[c[0].size()]*mi[c[1].size()]+mi[d[0].size()]*mi[d[1].size()])%p;
}
int sol1(vector<int> &a,int o,int x)
{
	if (!a.size()||o==-1) return mi[a.size()];
	vector<int> b[2];
	for (int x:a) b[x>>o&1].push_back(x);
	if (x>>o&1) return sol2(b[0],b[1],o-1,x);
	return (sol1(b[0],o-1,x)+sol1(b[1],o-1,x))%p;
}
int main()
{
	int n,i,x;
	ios::sync_with_stdio(0);cin.tie(0);
	mi[0]=1;for (i=1;i<N;i++) (mi[i]=mi[i-1]<<1)%=p;
	for (ll &x:mi) --x;
	cin>>n>>x;
	vector<int> a(n);
	for (int &x:a) cin>>x;
	ranges::sort(a);
	cout<<sol1(a,29,x)<<endl;
}