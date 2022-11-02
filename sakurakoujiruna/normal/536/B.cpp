#include <iostream>
using namespace std;

const int N = 1011111;
const int Inf = 0x3f3f3f3f;
typedef long long intl;
const intl Mod = (intl)1e9 + 7;

int p[N];
int y[N];

const int M = 20;
int pp[N][M];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string str;
	
	cin >> str;
	int t = str.size();
	str = '\0' + str;
	p[0] = p[1] = 0;
	int last = 0;
	pp[1][0] = 0;
	for(int i = 2; i <= t; i ++)
	{
		while(last > 0 && str[last + 1] != str[i])
			last = p[last];
		if(str[last + 1] == str[i])
			last ++;
		p[i] = last;
		pp[i][0] = p[i];
	}
	for(int j = 1; j < M; j ++)
		for(int i = 1; i <= t; i ++)
			pp[i][j] = pp[pp[i][j - 1]][j - 1];
	/*
	for(int i = 1; i <= t; i ++)
		cout << i << ' ' << p[i] << '\n';
		*/
	for(int i = 0; i < m; i ++)
		cin >> y[i];

	last = -Inf;
	intl ans = 1;
	int ptr = 0;
	for(int i = 1; i <= n; i ++)
		if(ptr < m && y[ptr] == i)
		{
			if(last + t <= i)
				last = i;
			else
			{
				int now = t;
				for(int j = M - 1; j >= 0; j --)
					if(pp[now][j] >= t - (i - last))
						now = pp[now][j];
				if(now != t - (i - last))
					ans = 0;
				last = i;
			}
			ptr ++;
		}
		else if(i >= last + t)
		{
			ans *= 26;
			ans %= Mod;
		}
	cout << ans << '\n';
	return 0;
}