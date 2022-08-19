#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 50005
#define iter set<th>::iterator
using namespace std;
int n, k;
struct nd
{
	int a[11];
	nd(){;}
	void rd()
	{
		for(int i = 1; i <= k; i++)
			scanf("%d", &a[i]);
	}
};
struct th
{
	int mn[11], mx[11];
	int sz;
	th(){;}
	th(nd x)
	{
		sz = 1;
		for(int i = 1; i <= k; i++)
			mn[i] = mx[i] = x.a[i];
	}
	bool operator < (const th &a)const
	{
		return mn[1] < a.mn[1];
	}
};
th mt(th a, th b)
{
	th f;
	f.sz = a.sz + b.sz;
	for(int i = 1; i <= k; i++)
		f.mn[i] = min(a.mn[i], b.mn[i]), 
		f.mx[i] = max(a.mx[i], b.mx[i]);
	return f;
}
bool chk(th a, th b)
{
	for(int i = 1; i <= k; i++)
		if(a.mx[i] > b.mn[i]) return 1;
	return 0;
}
set<th> x;
void upd(iter s, int tp)
{
	if(tp == 0)
	{
		iter t = s;
		t++;
		if(t == x.end())
			upd(s, 1);
		else
			if(chk(*s, *t))
			{
				th m = mt(*s, *t);
				x.erase(s), 
				x.erase(t);
				x.insert(m);
				s = x.find(m);
			//	cout<<"U"<<endl;
				upd(s, 0);
			}
			else upd(s, 1);
	}
	else
	{
		iter t = s;
		if(s == x.begin()) return;
		t--;
		if(chk(*t, *s))
		{
			th m = mt(*s, *t);
			x.erase(s), 
			x.erase(t);
			x.insert(m);
		//	cout<<"V"<<endl;
			s = x.find(m);
			upd(s, 0);
		}
		else return;
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		nd u;
		u.rd();
		th q = th(u);
		x.insert(q);
		iter v = x.find(q);
		upd(v, 0);
		v = x.end();
		v--;
		printf("%d\n", (*v).sz);
	}
	return 0;	
}