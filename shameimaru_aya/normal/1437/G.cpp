#include <bits/stdc++.h> 
using namespace std;
int n , m , cnt , ans , x , y , opt , top[330000] , ed[330000]; //Orz jiangly
int trie[30][330000] , fail[330000] , val[330000] , vis[330000] , pl[330000];
string s; 
queue< int > q;
multiset< int > maxx[330000]; 
inline void insert( string s , int t )
{
	int u = 0;
	for(int i = 0 ; i < (int)s.size() ; i++ )
	{
		if(!trie[s[i] - 'a'][u]) trie[s[i] - 'a'][u] = ++cnt;
		u = trie[s[i] - 'a'][u];
	}
	maxx[u].insert(0); ed[u] = 1; pl[t] = u;
	return ;
}
inline void init()
{
	for(int i = 0 ; i < 26 ; i++ )
		if(trie[i][0]) q.push(trie[i][0]);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(ed[fail[u]]) top[u] = fail[u];
		else top[u] = top[fail[u]];
		for(int i = 0 ; i < 26 ; i++ )
		{
			if(trie[i][u])
			{
				fail[trie[i][u]] = trie[i][fail[u]];
				q.push(trie[i][u]);
			}
			else trie[i][u] = trie[i][fail[u]];
		}
	}
	return ;
}
inline int ask( string s , int t )
{
	int u = 0 , ans = -1;
	for(int i = 0 ; i < (int)s.size() ; i++ )
	{
		u = trie[s[i] - 'a'][u];
		for(int j = u ; j && vis[j] != t ; j = top[j] )
		{
			ans = max(*maxx[j].rbegin() , ans);
			vis[j] = t;
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ )
	{
		cin >> s;
		insert(s , i);
	}
	init();
	for(int i = 1 ; i <= cnt ; i++ ) maxx[i].insert(-1);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d" , &opt);
		if(opt == 1)
		{
			scanf("%d%d" , &x , &y);
			maxx[pl[x]].erase(maxx[pl[x]].find(val[x]));
			val[x] = y;
			maxx[pl[x]].insert(val[x]);
		}
		else
		{
			cin >> s;
			printf("%d\n" , ask(s , i));
		}
	}
	return 0;
}
/*
6 4
aa
aaa
aaaaaa
aaaab
aabb
bb
*/