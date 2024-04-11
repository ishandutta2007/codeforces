#include <iostream>
#include <cstdio>
#include <set>
#define ii pair<int,int>
#define edge pair<int,ii>
#define X first
#define Y second
using namespace std;
const int maxn = 100000;
const int maxm = 1000000;
const int oo = (int) 1e9;
int n,m;
int a[maxm+1],b[maxm+1],w[maxm+1];
set<ii> S;
int cha[maxn+1];

int find_cha(int x)
{
	if (x==cha[x]) return x;
	else return cha[x] = find_cha(cha[x]);
}

void merge(int x,int y)
{
	cha[find_cha(x)] = find_cha(y);
}

bool check(int nw)
{
	S.erase(ii(w[1],1));
	w[1]=nw;
	S.insert(ii(w[1],1));
	for (int i=1; i<=n; i++)
		cha[i] = i;
	for (auto it=S.begin(); it!=S.end(); it++)
	{
		int e=(*it).Y;
		if (find_cha(a[e])!=find_cha(b[e]))
		{
			merge(a[e],b[e]);
			if (e==1)
				return true;
		}
		else
			if (e==1)
				return false;
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	
	for (int i=1; i<=m; i++)
	{
		cin >> a[i] >> b[i] >> w[i];
		S.insert(ii(w[i],i));
	}
	
	int dau = 0, cuoi = oo;
	do
	{
		int giua=(dau+cuoi)/2;
		if (check(giua)) dau=giua+1;
		else cuoi=giua-1;
	}
	while (dau<=cuoi);
	
	cout << cuoi;
	return 0;
}