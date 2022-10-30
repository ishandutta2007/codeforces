#include <bits/stdc++.h>
using namespace std;
int n , a[220000] , trie[6600000][2] , tot;
long long ans;
vector< int > qqq;
void insert( int m )
{
	int u = 0;
	for(int i = 29 ; i >= 0 ; i-- )
	{
		if(!trie[u][(m >> i) & 1]) trie[u][(m >> i) & 1] = ++tot;
		u = trie[u][(m >> i) & 1];
	}
}
void clear()
{
	for(int i = 0 ; i <= tot ; i++ ) trie[i][0] = trie[i][1] = 0;
	tot = 0;
}
int find( int m )
{
	int u = 0 , ans = 0;
	for(int i = 29 ; i >= 0 ; i-- )
	{
		int d = ((m >> i) & 1);
		if(trie[u][d]) u = trie[u][d];
		else u = trie[u][d ^ 1] , ans += (1 << i);
	}
	return ans;
}
void solve( vector< int > &a , int d )
{
	vector< int > a0 , a1;
	for(auto u : a)
	{
		if((u >> d) & 1) a1.push_back(u);
		else a0.push_back(u);
	}
	if(a0.size() && a1.size())
	{
		clear();
		if(a0.size() > a1.size()) swap(a0 , a1);
		for(auto u : a1) insert(u);
		int minn = 2e9;
		for(auto u : a0) minn = min(minn , find(u));
//		cerr << minn << ' ';
		ans += minn;	
	} 
	if(a0.size() && d) solve(a0 , d - 1); 
	if(a1.size() && d) solve(a1 , d - 1);
}
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , qqq.push_back(a[i]);
	solve(qqq , 29);
	cout << ans << endl;
    return 0;
}