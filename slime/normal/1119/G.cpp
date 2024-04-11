#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define iter set<th>::iterator
#define maxn 1000005
#define ll long long
using namespace std;
struct th
{
	int id, num;
	th(){id = 0, num = 0;}
	th(int a, int b){id = a, num = b;}
	bool operator < (const th &a)const
	{
		if(num != a.num) return num < a.num;
		return id < a.id;
	}
};
set<th> x;
vector<int> ns[maxn];
int n, m;
int hp[maxn];
ll dv = 0;
int a[maxn];
ll sm = 0;
void work(int bg, int n)
{

	if(!n)
		return ;
	else
	{
		if(bg == m)	
			a[bg] = n;
	//	cout<<"WORK"<<bg<<" "<<n<<endl;
	//	for(iter t = x.begin(); t != x.end(); t++)
	//		cout<<(*t).num<<" "<<(*t).id<<endl;
		while(1)
		{
			iter t = x.end();
			t--;
			if((*t).num < n) break;
			th n1 = (*t);
			x.erase(n1);
			int nd = n1.num / n;
			for(int j = bg; j <= m; j++)
				for(int tm = 0; tm < nd; tm++)
					ns[j].push_back(n1.id);
			sm -= nd * n;
			n1.num %= n;
			x.insert(n1);
		} 
		if(bg == m) return;
		iter q = x.begin();
		int nt = sm / n;
		a[bg] = (*q).num;
		ns[bg].push_back((*q).id);
		x.erase(q);
		sm -= nt * a[bg];
		
		if(a[bg])
		{
			iter t = x.begin();
			for(int j = 1; j < nt; j++)
			{
				th q1 = *t;
				t++;
				x.erase(q1);
				ns[bg].push_back(q1.id);
				q1.num -= a[bg];
				x.insert(q1);
			}
		}
		work(bg + 1, n - a[bg]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	ll sum = 0;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &hp[i]);
		sum += hp[i];
	}
	dv = sum / n;
	if(sum % n) dv++;
	sum = dv * n;
	sm = sum;
	for(int i = 1; i < m; i++)
		sum -= hp[i];
	hp[m] = sum;
	for(int i = 1; i <= m; i++)
		x.insert(th(i, hp[i]));
	work(1, n);
	cout<<dv<<endl;
	for(int i = 1; i <= m; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int j = 1; j <= m; j++)
		while(ns[j].size() < dv)
			ns[j].push_back(1);
	for(int i = 1; i <= dv; i++)
	{
		for(int j = 1; j <= m; j++)
			printf("%d ", ns[j][i - 1]);
		printf("\n");
	}
	return 0;
 }