#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
#define mod 998244353
int n;
int ch[maxn][2], son[maxn], sz[maxn];
int tp[maxn]; // 0 : and 1 : or 2 : xor 3 : not 4 : ne
int fa[maxn], top[maxn], szs[maxn];
int fr[maxn][2];
int tr[maxn];
int cal(int a, int b, int c)
{
	if(a == 0) return b & c;
	if(a == 1) return b | c;
	if(a == 2) return b ^ c;
	return b ^ 1;
}
void dfs1(int a)
{
	szs[a] = 1;
	if(tp[a] == 4)  
		tr[a] = ch[a][0];
	else
	{
		for(int i = 0; i < sz[a]; i++)
		{
			fa[ch[a][i]] = a;
			dfs1(ch[a][i]);
			szs[a] += szs[ch[a][i]];
			if(szs[ch[a][i]] > szs[son[a]]) son[a] = ch[a][i];
		}
		tr[a] = cal(tp[a], tr[ch[a][0]], tr[ch[a][1]]);
	//	cout<<a<<" "<<son[a]<<endl;
	}
}
void dfs2(int a)
{
	if(tp[a] == 4) return;
//	cout<<"DFS"<<a<<endl;
//cout<<a<<" "<<son[a]<<" "<<fr[a][0]<<" "<<fr[a][1]<<" "<<tr[a]<<endl;
	top[son[a]] = top[a];
	int ot = ch[a][0] + ch[a][1] - son[a];
	for(int j = 0; j < 2; j++)
		fr[son[a]][j] = fr[a][cal(tp[a], j, tr[ot])];
	dfs2(son[a]);
	
	if(sz[a] == 2)
		top[ot] = ot, 
		fr[ot][0] = 0, 
		fr[ot][1] = 1, 
		dfs2(ot);
}
int ns[maxn], cnt = 0;
int cal(int a, int ns)
{
//	cout<<"CAL"<<a<<" "<<ns<<" "<<top[a]<<" "<<fa[a]<<endl;
//	system("pause");
	if(a == 1) return ns;
	if(a == top[a])
	{
		//cout<<"F1"<<" "<<fa[a]<<" "<<tr[son[fa][a]endl;
		return cal(fa[a], cal(tp[fa[a]], ns, tr[son[fa[a]]]));
	}
	else
		return cal(top[a], fr[a][ns]);
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		char inp[10];
		scanf("%s", inp);
		int cs = 2;
		if(inp[0] == 'I') tp[i] = 4, cs = 1;
		else if(inp[0] == 'A') tp[i] = 0;
		else if(inp[0] == 'O') tp[i] = 1;
		else if(inp[0] == 'X') tp[i] = 2;
		else tp[i] = 3, cs = 1;
		sz[i] = cs;
		for(int j = 0; j < cs; j++)
			cin>>ch[i][j];
	}
	dfs1(1);
	top[1] = 1;
	fr[1][1] = 1;
	dfs2(1);
//	cout<<"AFT"<<endl;
//cout<<3<<" "<<top[3]<<" "<<fa[3]<<endl;
	for(int i = 1; i <= n; i++)
	{
		if(tp[i] != 4) continue;
		cout<<cal(i, ch[i][0] ^ 1);	
	}
	cout<<endl;
	return 0;	
}