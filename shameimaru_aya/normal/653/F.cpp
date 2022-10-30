#include <bits/stdc++.h>
using namespace std;
int n , sum[550000] , fa[20][550000] , pl[1100000];
int st[20][550000] , dep[550000] , cur , las , tot;
long long ans;
string s;
struct node
{
	int ch[2] , link , endp , len;
} sam[1100000];
void insert( int c , int endp )
{
	cur = ++tot; int u = las; sam[cur].endp = endp; sam[cur].len = sam[las].len + 1;
	while(~u && !sam[u].ch[c]) sam[u].ch[c] = cur , u = sam[u].link;
	if(~u)
	{
		int p = u , q = sam[u].ch[c];
		if(sam[q].len == sam[p].len + 1) sam[cur].link = q;
		else
		{
			int cl = ++tot; sam[cl] = sam[q]; sam[cl].len = sam[p].len + 1;
			sam[cur].link = sam[q].link = cl;
			while(~u && sam[u].ch[c] == q) sam[u].ch[c] = cl , u = sam[u].link;
		}
	}
	las = cur;
}
void build()
{
	for(int i = 1 ; i <= n ; i++ ) st[0][i] = sum[i];
	for(int i = 1 ; i <= 18 ; i++ )
		for(int j = 1 ; j + (1 << i - 1) <= n ; j++ ) 
			st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << i - 1)]);
}
int ask( int l , int r )
{
	int k = log2(r - l + 1);
	return min(st[k][l] , st[k][r - (1 << k) + 1]);
}
int main()
{
	sam[0].link = -1;
	cin >> n >> s; s = '$' + s;
	for(int i = n ; i >= 1 ; i-- ) sum[i] = sum[i + 1] + (s[i] == ')' ? 1 : -1); build();
	for(int i = 1 ; i <= n ; i++ ) insert(s[i] == '(' , i);
	memset(pl , -1 , sizeof(pl)); 
	for(int i = n + 1 ; i >= 1 ; i-- )
	{
		if(~pl[sum[i] + 500000]) 
			if(ask(i , pl[sum[i] + 500000]) >= sum[i]) fa[0][pl[sum[i] + 500000]] = i;
		pl[sum[i] + 500000] = i;
	}
//	for(int i = 1 ; i <= n + 1 ; i++ ) cerr << fa[0][i] << ' '; cerr << endl;
	for(int i = 1 ; i <= n + 1 ; i++ ) 
	{
		dep[i] = dep[fa[0][i]] + 1;
		for(int j = 1 ; j <= 18 ; j++ ) fa[j][i] = fa[j - 1][fa[j - 1][i]];
	}
	for(int i = 1 ; i <= tot ; i++ )
	{
		int p = sam[i].endp , r = p - (sam[sam[i].link].len + 1) + 1 , l = p - sam[i].len + 1;
		int u = p + 1;
		for(int i = 18 ; i >= 0 ; i-- ) 
			if(fa[i][u] > r) u = fa[i][u];
		u = fa[0][u]; ans += dep[u] + 1;
//		cerr << i << ' ' << l << ' ' << r << ' ' << p << ' ' << dep[u] << ' ';
		u = p + 1;
		for(int i = 18 ; i >= 0 ; i-- ) 
			if(fa[i][u] >= l) u = fa[i][u];
		ans -= dep[u];
//		cerr << dep[u] << endl;
	}
	printf("%lld" , ans);
	return 0;
}
/*
30
()(())(())(())()(())()()()(()(
*/