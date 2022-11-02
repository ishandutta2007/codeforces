#include<bits/stdc++.h>
using namespace std;
int n , ans , x , y , fa[110000] , siz[110000] , num[110000] , pl[110000];
int fst[110000] , nex[220000] , v[220000] , tot , a[110000] , b[110000];
int qwq , sav , dlt , Fst[2][110000] , End[2][110000] , Nex[110000];
queue< int > id[110000];
long long upp , dwn , k , num0 , num1;
inline long long read()
{
    long long a = 0; char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') a = (a << 1) + (a << 3) + (c ^ 48) , c = getchar();
    return a;
}
inline long long Min( long long a , long long b )
{
	return (a < b ? a : b);
}
inline long long Max( long long a , long long b )
{
	return (a > b ? a : b);
}
inline int getf( int a )
{
	if(siz[a] || a == 1) return a;
	return fa[a] = getf(fa[a]);
}
inline void add( int a , int b )
{
	nex[++tot] = fst[a] , fst[a] = tot;
	v[tot] = b;
}
void dfs1( int u , int f )
{
	fa[u] = f; siz[u] = 1;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == f) continue;
		dfs1(v[i] , u);
		siz[u] += siz[v[i]];
		upp += (num[v[i]] = Min(siz[v[i]] , n - siz[v[i]]));
		dwn += siz[v[i]] & 1;
		num1 += siz[v[i]] & 1;
	}
//	cerr << u << ' ' << siz[u] << endl;
	return ;
}
inline bool check( int qwq )
{
	long long cnt = upp;
	for(int i = 1 ; i <= n ; i++ )
		if(num[i] > qwq - ((num[i] ^ qwq) & 1))
			cnt -= num[i] - qwq + ((num[i] ^ qwq) & 1);
	if(qwq == ans) 
	{
//		cerr << cnt << ' ';
		num1 = Min(num1 , (k - cnt) >> 1);
		num0 = Max(0ll , (k - cnt - (num1 << 1)) >> 1);
	}
//	cerr << qwq << ' ' << cnt << ' ' << k << endl;
	return (cnt > k);
}
void binary( int l , int r )
{
	if(l > r) return ;
	int mid = l + r >> 1;
	if(check(mid)) 
	{
		ans = mid;
		binary(l , mid - 1);
	}
	else binary(mid + 1 , r);
	return ;
}
void dfs2( int u )
{
	siz[u] = 1;
	dlt = Max(0 , num[u] - (ans - ((num[u] ^ ans) & 1)));
	if(dlt >= 2)
	{
		if(((num[u] ^ ans) & 1) && num1) num1-- , num[u] += 2;
		if(!((num[u] ^ ans) & 1) && num0) num0-- , num[u] += 2;
	}
	num[u] -= dlt;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa[u]) continue;
		dfs2(v[i]);
		siz[u] += num[v[i]];
	}
	return ;
}
void dfs3( int u , int f )
{
	pl[u] = 1;
	if(!Fst[0][u]) End[0][u] = u;
	Nex[u] = Fst[0][u]; Fst[0][u] = u;
	siz[u] = siz[u] - num[u] >> 1;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == f) continue;
		dfs3(v[i] , u);
		while(Fst[0][u] && Fst[1][u] && siz[u])
		{
			a[++tot] = Fst[0][u] , b[tot] = Fst[1][u];
			id[u].push(tot); siz[u]--;
			Fst[0][u] = Nex[Fst[0][u]] , Fst[1][u] = Nex[Fst[1][u]];
		}
		if(Fst[pl[u]][u]) pl[u] ^= 1;
	}
//	cerr << u << ' ' << q[0][u].size() << ' ' << q[1][u].size() << endl;
	while(Fst[0][u] && siz[u])
	{
		qwq = id[u].front(); id[u].pop(); siz[u]--;
		sav = b[qwq]; b[qwq] = Fst[0][u]; Fst[0][u] = Nex[Fst[0][u]];
		a[++tot] = sav; b[tot] = Fst[0][u]; Fst[0][u] = Nex[Fst[0][u]];
	}
	while(Fst[1][u] && siz[u])
	{
		qwq = id[u].front(); id[u].pop(); siz[u]--;
		sav = b[qwq]; b[qwq] = Fst[1][u]; Fst[1][u] = Nex[Fst[1][u]];
		a[++tot] = sav; b[tot] = Fst[1][u]; Fst[1][u] = Nex[Fst[1][u]];
	}
	int awa = getf(u);
	if(Fst[0][u])
	{
		Nex[End[0][u]] = Fst[pl[awa]][awa];
		if(!Fst[pl[awa]][awa]) End[pl[awa]][awa] = End[0][u];
		Fst[pl[awa]][awa] = Fst[0][u];
	}
	if(Fst[1][u])
	{
		Nex[End[1][u]] = Fst[pl[awa]][awa];
		if(!Fst[pl[awa]][awa]) End[pl[awa]][awa] = End[1][u];
		Fst[pl[awa]][awa] = Fst[1][u];
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	n = read() , k = read();
	for(int i = 1 ; i < n ; i++ )
	{
		x = read() , y = read();
		add(x , y); add(y , x);
	}
//	cerr << clock() << endl;
	dfs1(1 , 0);
	if(k > upp || k < dwn || ((k ^ dwn) & 1)) 
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	ans = n + 1;
	binary(0 , n + 1);
	ans--; check(ans);
//	cerr << ans << ' ' << num0 << ' ' << num1 << '\n';
	tot = 0;
	dfs2(1);
	dfs3(1 , 0); //slow
//	cerr << clock();
//	cerr << sum << endl;
	for(int i = 1 ; i <= tot ; i++ ) printf("%d %d\n" , a[i] , b[i]);
    return 0;
}
/*
*/