#include<bits/stdc++.h>
using namespace std;
int n , m , T , x , y , xx[110000] , yy[110000] , id[1100] , tot;
int msk[1100] , in[1100] , cnt , pl[1100] , B , f[1 << 22] , opt[8800] , s[8800] , t[8800];
char ch[30];
vector< int > son[1100];
queue< int > q;
int main()
{
	scanf("%d%d%d" , &n , &m , &T); B = min(20 , n);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &xx[i] , &yy[i]);
		son[xx[i]].push_back(yy[i]); in[yy[i]]++;
	}
	for(int i = 1 ; i <= n ; i++ ) 
		if(!in[i]) t[i] = ++tot , q.push(i);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0 ; i < son[u].size() ; i++ )
		{
			in[son[u][i]]--;
			if(!in[son[u][i]]) t[son[u][i]] = ++tot , q.push(son[u][i]);
		}
	}
	for(int i = 1 ; i <= n ; i++ ) id[i] = i;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		if(t[i] > n - B) 
		{
			cnt++;
			swap(id[i] , id[cnt]);
		}
	}
	for(int i = 1 ; i <= n ; i++ ) son[i].clear() , pl[id[i]] = i;
	tot = 0;
	for(int i = 1 ; i <= m ; i++ ) 
	{
		if(id[xx[i]] <= B && id[yy[i]] <= B) 
		{
			opt[++tot] = 1; s[tot] = xx[i]; t[tot] = yy[i]; 
			fflush(stdout);
		}
		if(id[xx[i]] <= B && id[yy[i]] > B) 
		{
			opt[++tot] = 1; s[tot] = xx[i]; t[tot] = yy[i]; 
			fflush(stdout);
		}
		if(id[xx[i]] > B && id[yy[i]] <= B) msk[id[xx[i]]] |= (1 << (id[yy[i]] - 1));
	}
	for(int i = 1 ; i <= B ; i++ )
	{
		for(int j = i + 1 ; j <= B ; j++ )
		{
			opt[++tot] = 0; s[tot] = pl[i]; t[tot] = pl[j]; 
			fflush(stdout);
		}
	}
	for(int i = B + 1 ; i <= n ; i++ )
	{
		opt[++tot] = 0; s[tot] = pl[i]; t[tot] = pl[i]; 
		fflush(stdout);
		if(!f[msk[i]]) f[msk[i]] = i;
		else
		{
			queue< int > q , dep;
			q.push(msk[i]); dep.push(0);
			while(!q.empty())
			{
				int u = q.front() , d = dep.front(); q.pop(); dep.pop();
				if(!f[u])
				{
					int qwq = msk[i] ^ u;
					msk[i] = u; f[u] = i;
					for(int j = 0 ; j < B ; j++ )
					{
						if((qwq & (1 << j)) && (u & (1 << j))) 
							opt[++tot] = 0 , s[tot] = pl[i] , t[tot] = pl[j + 1]; 
						if((qwq & (1 << j)) && !(u & (1 << j))) 
							opt[++tot] = 1 , s[tot] = pl[i] , t[tot] = pl[j + 1]; 
					}
					break;
				}
				for(int j = 0 ; j < B ; j++ )
				{
					q.push(u ^ (1 << j)); dep.push(d + 1);
				}
			}
		}
	}
	printf("%d\n" , tot); 
	for(int i = 1 ; i <= tot ; i++ )
	{
		if(opt[i]) printf("- ");
		else printf("+ ");
		printf("%d %d\n" , s[i] , t[i]);
	}
	while(T--)
	{
		int msk = 0 , ff = 0;
		for(int i = 1 ; i <= B ; i++ )
		{
			printf("? 1 %d\n" , pl[i]); fflush(stdout);
			scanf("%s" , ch);
			if(ch[0] == 'L')
			{
				printf("! %d\n" , pl[i]); fflush(stdout);
				scanf("%s" , ch); ff = 1;
				if(ch[0] != 'C') return 0;
				break;
			}
			if(ch[0] == 'W') msk |= (1 << i - 1);
		}
		if(!ff)
		{
			printf("! %d\n" , pl[f[msk]]); fflush(stdout); scanf("%s" , ch); 
			if(ch[0] != 'C') return 0;
		}
	}
	return 0;
}
/*
2
1 2
*/