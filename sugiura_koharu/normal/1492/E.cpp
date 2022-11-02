#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector <int> v[250005];
int n,m;
inline int cnt(vector <int> x,int y)
{
	int cnt=0;
	for(int i=0;i<m;i++)
		cnt+=x[i]!=v[y][i];
	return cnt;
}
inline void check(vector <int> s)
{
	for(int i=1;i<=n;i++) if(cnt(s,i)>=3) return ;
	puts("Yes");
	for(auto t:s) cout << t << " ";
	exit(0);
}//
int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	vector <int> s;
	for(int i=0;i<m;i++) s.push_back(v[1][i]);
	check(s);
	for(int i=1;i<=n;i++)
	{
		int X=cnt(v[1],i);
		if(X<=2) continue;
		if(X>4)
		{
			puts("No");
			return 0;
		}
		if(X==4)
		{
			int a=m,b=m,c=m,d=m;
			for(int j=0;j<m;j++)
			{
				if(v[1][j]!=v[i][j])
				{
					if(m==a) a=j;
					else if(m==b) b=j;
					else if(m==c) c=j;
					else if(m==d) d=j;
				}
			}
			s[a]=v[i][a],s[b]=v[i][b],s[c]=v[1][c],s[d]=v[1][d],check(s);
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[i][c],s[d]=v[1][d],check(s);
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[1][c],s[d]=v[i][d],check(s);
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[i][c],s[d]=v[1][d],check(s);
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[1][c],s[d]=v[i][d],check(s);
			s[a]=v[1][a],s[b]=v[1][b],s[c]=v[i][c],s[d]=v[i][d],check(s);
			puts("No");
			return 0;
		}
		if(X==3)
		{
			int a=m,b=m,c=m,d=m;
			for(int j=0;j<m;j++)
			{
				if(v[1][j]!=v[i][j])
				{
					if(m==a) a=j;
					else if(m==b) b=j;
					else if(m==c) c=j;
				}
			}
			s[a]=v[i][a],s[b]=v[i][b],s[c]=v[1][c],check(s);
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[i][c],check(s);
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[i][c],check(s);
			s[a]=v[1][a],s[b]=v[1][b],s[c]=v[i][c],check(s);
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[1][c],check(s);
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[1][c],check(s);
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[1][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[c]=v[i][c];break;}}
			check(s);
			
			s[a]=v[i][a],s[b]=v[1][b],s[c]=v[1][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[b]=v[i][b];break;}}
			check(s);
			
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[1][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[c]=v[i][c];break;}}
			check(s);
			
			s[a]=v[1][a],s[b]=v[i][b],s[c]=v[1][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[a]=v[i][a];break;}}
			check(s);
			
			s[a]=v[1][a],s[b]=v[1][b],s[c]=v[i][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[a]=v[i][a];break;}}
			check(s);
			
			s[a]=v[1][a],s[b]=v[1][b],s[c]=v[i][c];
			for(int i=1;i<=n;i++) {if(cnt(s,i)>2){s[b]=v[i][b];break;}}
			check(s);
			
			puts("No");
			return 0;
		}
	}
	puts("No");
	return 0;
}