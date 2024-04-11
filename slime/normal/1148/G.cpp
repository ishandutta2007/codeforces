#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define iter set<th>::iterator
#define maxn 100005
#define S 10000005
#define ll long long
using namespace std;
const int V = 5000;
bool bpr[V];
int prs[V], prcnt = 0;
struct th
{
	int r[10];
	int sz;
	int u[305], tp[305]; 
	th(){sz = 0;}
	th(int x)
	{
		sz = 0;
		for(int i = 0; i < prcnt; i++)
			if(x % prs[i]) continue;
			else
			{
				r[sz++] = prs[i];
				while(!(x % prs[i]))
					x /= prs[i];
			}
		if(x != 1) r[sz++] = x;
		for(int i = 0; i < (1 << sz); i++)
		{
			int nt = -1, j = 1;
			for(int k = 0; k < sz; k++)
				if(i & (1 << k))
					j *= r[k], 
					nt *= -1;
			u[i] = j;
			tp[i] = nt;
		}
	}
}p[maxn];
int a[maxn];
int sm[S];
void upd(th x, int tp)
{
	for(int i = 0; i < (1 << x.sz); i++)
		sm[x.u[i]] += tp;
}
int q(th x)
{
	int ans = 0;
	for(int i = 1; i < (1 << x.sz); i++)
		ans += sm[x.u[i]] * x.tp[i];
	return ans;
}
int cnt = 0;
int nm[maxn];
int fl[maxn];
vector<int> nx[maxn];
void work(int l, int r, vector<int> g)
{
	if(l == r) 
	{
		for(int i = 0; i < g.size(); i++)
			nx[l].push_back(g[i]);
		return ;
	}
	int mid = (l + r) >> 1;
	vector<int> u, v;
	for(int i = l; i <= mid; i++)
		upd(p[nm[i]], 1);
	for(int i = 0; i < g.size(); i++)
	{
		int ns = q(p[g[i]]);
		if(ns == mid - l + 1) v.push_back(g[i]);
		else u.push_back(g[i]);
	}
	for(int i = l; i <= mid; i++)
		upd(p[nm[i]], -1);
	work(l, mid, u);
	work(mid + 1, r, v);
}
struct sr
{
	int id, num;
	bool operator < (const sr &u)const
	{
		return num < u.num;
	}
}ng[maxn];
vector<int> ans;
int main()
{
	for(int i = 0; i < V; i++)
		bpr[i] = 1;
	for(int i = 2; i < V; i++)
		if(bpr[i])
		{
			prs[prcnt++] = i;
			for(int j = 2; j * i < V; j++)
				bpr[i * j] = 0;
		}
//	cout<<prcnt<<endl;
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), 
		p[i] = th(a[i]);
	vector<int> s;
//	cout<<"AF"<<endl;
	for(int i = 1; i <= n; i++)
	{
		int uj = q(p[i]);
		if(uj == cnt)
		{
			nm[cnt++] = i, 
			upd(p[i], 1);
			nx[cnt - 1].push_back(i);
		//	cout<<"!!!"<<endl;
			if(cnt >= k) 
				break;
		}
		else fl[i] = 1, s.push_back(i);
//		cout<<i<<endl;
	}
	for(int i = 1; i <= n; i++)
		if(!fl[i])
			upd(p[i], -1);
//			cout<<"AF"<<i<<endl;
	if(cnt >= k)
		for(int i = 0; i < k; i++)
			printf("%d ", nm[i]);
	else
	{
	//	cout<<"F"<<endl;
		work(0, cnt - 1, s);
	//	cout<<"AF"<<endl;
		for(int i = 0; i < cnt; i++)
			ng[i].id = i, 
			ng[i].num = nx[i].size();
		sort(ng, ng + cnt);
		for(int i = cnt - 1; i >= 0; i--)
			if(k >= 2 && ng[i].num >= 2)
			{
				int nid = ng[i].id;
				ans.push_back(nx[nid][0]), 
				ans.push_back(nx[nid][1]);
				k -= 2;
			}
		for(int i = cnt - 1; i >= 0; i--)
		{
			int npl = 2;
			int nid = ng[i].id;
			while(npl < nx[nid].size() && k)
			{
				ans.push_back(nx[nid][npl]), 
				npl++, 
				k--;
			}
		}
		for(int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
	}
	return 0;
 }