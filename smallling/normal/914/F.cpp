#include <bits/stdc++.h>

using namespace std;

const int N = 100010; 

bitset<N> bit[26], Full, Ans; 

char s[N], ss[N];

int main()
{ 
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		Full[i] = 1, bit[s[i] - 'a'][i] = 1;
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int opt;
		scanf("%d", &opt);
		if(opt == 1)
		{
			int x;
			char c[2];
			scanf("%d%s", &x, c);
			bit[s[x] - 'a'][x] = 0;
			bit[c[0] - 'a'][x] = 1;
			s[x] = c[0];
		}
		else
		{
			int l, r;
			scanf("%d%d%s", &l, &r, ss);
			int mm = strlen(ss);
			Ans = Full;
			for(int i = 0; i < mm; i++)
				Ans &= bit[ss[i] - 'a'] >> i;
			Ans >>= l;
			Ans <<= N - (r - l - mm + 2);
			printf("%d\n", Ans.count());
		}
	}
}