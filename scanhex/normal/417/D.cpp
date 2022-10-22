#include <string>
#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

const long long INF = 3074457345618258602L; 
int n;
int m;
int a;
ll *cost, *mon;
ll b;
ll res = INF;     

struct Friend
{
	ll x, k;
	int mask;
	bool operator <(Friend o)
	{
		return this->k < o.k; 
	}	
};

Friend* f;
    
void pereb()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 1 << m; ++j)
		{	
			int nm = j | f[i].mask;
			cost[nm] = min(cost[nm], cost[j] + f[i].x);          
		}     	      
		if (cost[(1 << m) - 1] < INF)
		{
			res = min(cost[(1 << m) - 1] + b * f[i].k, res);	
		} 
	}
}

int main() 
{
	cin >> n;
	cin >> m;
	cin >> b;
	cost = new long long[1 << m];   
	for (int i = 0; i < 1 << m; ++i) 
	{
		cost[i] = INF;
	}
	cost[0] = 0;      
	f = new Friend[n];
	for (int i = 0; i < n; ++i) 
	{
		f[i] = Friend();
		f[i].x = f[i].k = f[i].mask = 0;
	}                 
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i].x;
		cin >> f[i].k;
		int mi;
		cin >> mi;
		int msk = 0;
		for (int j = 0; j < mi; ++j)
		{
			int pr;
			cin >> pr;
			--pr;
			msk += (1 << pr);
		}
		f[i].mask = msk;
	}
	sort(f, f + n);
	pereb();
	cout << (res == INF ? -1 : res);
}