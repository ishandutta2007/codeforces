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
	const int BUF = 1048576;
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
	void inputstr(string &ret)
	{
		char ch = inputchar();
		if(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch;
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret += ch;
			ch = inputchar();
		}
	}
}
const int maxn = 5005, maxm = 5e5 + 5;
int w[20];
int cnt[maxm];
int v[maxn][maxn];
int q[maxn][105];
int asd[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	using namespace Input;
	int n, m, T;
	inputnum(n);
	inputnum(m);
	inputnum(T);
	for(int i = 0; i < n; i ++)
		inputnum(w[i]);
	for(int i = 0; i < (1 << n); i ++)
		for(int j = 0; j < n; j ++)
			if(!((i >> j) & 1))
				asd[i] += w[j];
	for(int i = 0; i < (1 << n); i ++)
		for(int j = 0; j < (1 << n); j ++)
			v[i][j] = asd[i ^ j];
	for(int i = 1; i <= m; i ++)
	{
		string s;
		inputstr(s);
		int x = 0;
		for(int j = n - 1; j >= 0; j --)
			x = x * 2 + s[j] - '0';
		cnt[x] ++;
	}
	for(int i = 0; i < (1 << n); i ++)
		for(int j = 0; j < (1 << n); j ++)
			if(v[i][j] <= 100)
				q[i][v[i][j]] += cnt[j];
	for(int i = 0; i < (1 << n); i ++)
		for(int j = 1; j <= 100; j ++)
			q[i][j] += q[i][j - 1];
	while(T --)
	{
		string t;
		inputstr(t);
		int x = 0;
		for(int j = n - 1; j >= 0; j --)
			x = x * 2 + t[j] - '0';
		int k;
		inputnum(k);
		cout << q[x][k] << endl;
	}
	
	return 0;
}