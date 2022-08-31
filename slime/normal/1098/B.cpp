#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 150005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n, m;
struct ans
{
	vector<int> x[maxn];
	int nans;
	ans()
	{
		nans = 0;
		for(int j = 0; j < maxn; j++)
			x[j].clear();
	}
	bool operator < (const ans & x)const
	{
		return nans < x.nans;
	}
};

vector<int> mp[maxn];
int tr(char a)
{
	if(a == 'A') return 0;
	else if(a == 'C') return 1;
	else if(a == 'G') return 2;
	else return 3;
}
char tr(int a)
{
	if(a == 0) return 'A';
	if(a == 1) return 'C';
	if(a == 2) return 'G';
	return 'T';
}
char inp[maxn];	
ans k1;	
ans x1;
int main()
{
//	cout<<"WAAA"<<endl;
	cin>>n>>m;
	for(int j = 1; j <= n; j++)
	{
		mp[j].resize(m + 1);
		scanf("%s", inp + 1);
		for(int k = 1; k <= m; k++)
			mp[j][k] = tr(inp[k]);
	}
	// 

	k1.nans = maxn * 10;
	for(int j = 0; j < 4; j++)
		for(int k = j + 1; k < 4; k++)
		{
			int fr[2][2];
			fr[0][0] = j, fr[0][1] = k;
			int cnt = 0;
			for(int s = 0; s < 4; s++)
				if(s != j && s != k)
				    fr[1][cnt++] = s;
			x1 = ans();
			for(int l = 1; l <= n; l++)
			{
				int a[2] = {0, 0};
				for(int s = 0; s < 2; s++)
					for(int t = 1; t <= m; t++)
						if(mp[l][t] != fr[l & 1][(t & 1) ^ s])
							a[s]++;
				int mpl = 0;
				if(a[1] < a[0]) mpl = 1;
				x1.nans += a[mpl];
				x1.x[l].resize(m + 1);
				for(int t = 1; t <= m; t++)
					x1.x[l][t] = fr[l & 1][(t & 1) ^ mpl];
			}
			if(x1 < k1) k1 = x1;
		}
//	cout<<"AFT"<<endl;
	// 
	for(int j = 0; j < 4; j++)
		for(int k = j + 1; k < 4; k++)
		{
			int fr[2][2];
			fr[0][0] = j, fr[0][1] = k;
			int cnt = 0;
			for(int s = 0; s < 4; s++)
				if(s != j && s != k)
				    fr[1][cnt++] = s;
			x1 = ans();
			for(int l = 1; l <= n; l++)
				x1.x[l].resize(m + 1);
			for(int l = 1; l <= m; l++)
			{
				int a[2] = {0, 0};
				for(int s = 0; s < 2; s++)
					for(int t = 1; t <= n; t++)
						if(mp[t][l] != fr[l & 1][(t & 1) ^ s])
							a[s]++;
				int mpl = 0;
				if(a[1] < a[0]) mpl = 1;
				x1.nans += a[mpl];
				for(int t = 1; t <= n; t++)
					x1.x[t][l] = fr[l & 1][(t & 1) ^ mpl];
			}
			if(x1 < k1) k1 = x1;
		}
//	cout<<"AAAA"<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			printf("%c", tr(k1.x[i][j]));
		printf("\n");
	}
	return 0;
 }