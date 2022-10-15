#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char mp[MAXN][MAXN];
int n,m;
int row[MAXN],col[MAXN];
bool used[3];
int num(char c)
{
	if(c=='R') return 1;
	if(c=='B') return 2;
	if(c=='G') return 3;
	return 100;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	memset(row,-1,sizeof(row));
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		int x=num(mp[i][0]);
		bool f=true;
		for(int j=1;j<m;j++)
			if(num(mp[i][j])!=x) {f=false; break;}
		if(f) row[i]=x;
	}
	for(int i=0;i<m;i++)
	{
		int x=num(mp[0][i]);
		bool f=true;
		for(int j=1;j<n;j++)
			if(num(mp[j][i])!=x) {f=false; break;}
		if(f) col[i]=x;
	}
	bool f=true;
	if(n%3==0)
	{
		for(int i=0;i<n;i++)
			if(row[i]==-1) f=false;
		for(int i=1;i<n/3;i++)
			if(row[i]!=row[i-1]) {f=false; break;}
		for(int i=n/3+1;i<n*2/3;i++)
			if(row[i]!=row[i-1]) {f=false; break;}
		for(int i=n*2/3+1;i<n;i++)
			if(row[i]!=row[i-1]) {f=false; break;}
		if(f&&row[0]+row[n/3]+row[n*2/3]==6&&row[0]!=row[n/3]&&row[0]!=row[n*2/3]&&row[n/3]!=row[n*2/3]) {puts("YES"); return 0;}
	}
	f=true;
	if(m%3==0)
	{
		for(int i=0;i<m;i++)
			if(col[i]==-1) f=false;
		for(int i=1;i<m/3;i++)
			if(col[i]!=col[i-1]) {f=false; break;}
		for(int i=m/3+1;i<m*2/3;i++)
			if(col[i]!=col[i-1]) {f=false; break;}
		for(int i=m*2/3+1;i<m;i++)
			if(col[i]!=col[i-1]) {f=false; break;}
		if(f&&col[0]+col[m/3]+col[m*2/3]==6&&col[0]!=col[m/3]&&col[0]!=col[m*2/3]&&col[m/3]!=row[m*2/3]) {puts("YES"); return 0;}
	}
	puts("NO");
	return 0;
}