#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
namespace Input
{
	const int BUF = 1 << 20;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
	char inputchar()
	{
		if(head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	void inputnum(int &ret)
	{
		char ch = inputchar();
		while(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch - '0';
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret = ret * 10 + ch - '0';
			ch = inputchar();
		}
	}
}
namespace Output
{
	const int BUF = 1 << 20;
	char buf[BUF + 1];
	char *head = buf, *tail = buf + BUF;
	void outputflush()
	{
		fwrite(buf, 1, head - buf, stdout);
		head = buf;
	}
	void outputchar(char c)
	{
		if(head == tail)
			outputflush();
		*head ++ = c;
	}
	void outputnum(int x)
	{
		static int p = 0;
		static char tmp[15];
		if(x == 0)
			tmp[p ++] = '0';
		while(x)
		{
			tmp[p ++] = (char)(x % 10 + '0');
			x /= 10;
		}
		while(p)
			outputchar(tmp[-- p]);
	}
}
const int maxn = 1e6 + 5;
int fa[maxn], dp[maxn], mx[maxn], cnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	using namespace Input;
	using namespace Output;
	int n;
	inputnum(n);
	int ans = 0;
	for(int i = 2; i <= n + 1; i ++)
	{
		inputnum(fa[i]);
		dp[i] = 1;
		for(int p = i, f = fa[i]; p > 1; p = f, f = fa[f])
		{
			if(dp[p] > ans)
				ans = dp[p];
			if(dp[p] > dp[f])
			{
				dp[f] = mx[f] = dp[p];
				cnt[f] = 1;
			}
			else if(dp[p] > mx[f])
			{
				mx[f] = dp[p];
				cnt[f] = 1;
				break;
			}
			else if(dp[p] == mx[f] && cnt[f] == 1)
			{
				dp[f] ++;
				cnt[f] ++;
			}
			else
				break;
		}
		outputnum(ans);
		outputchar(' ');
	}
	outputchar('\n');
	outputflush();
	
	return 0;
}