#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[110000];
int pos[110000], m, used[110000];
int a[110000], b[110000];
int c[110000], d[110000];
int t1[410000], t2[410000];

int n;

void build(int t[], int c[], int i, int l, int r)
{
	if (l == r) {t[i] = l; return ;}

	build(t, c, 2 * i, l, (l + r) / 2);
	build(t, c, 2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = c[t[2 * i]] < c[t[2 * i + 1]] ? t[2 * i] : t[2 * i + 1];
}

void update(int t[], int c[], int i, int l, int r, int k, int newval)
{
	if (l == r)
	{
		c[l] = newval;
		t[i] = l;
		return ;
	}

	if (k > (l + r) / 2)
		update(t, c, 2 * i + 1, (l + r) / 2 + 1, r, k, newval); else
		update(t, c, 2 * i, l, (l + r) / 2, k, newval);

	t[i] = c[t[2 * i]] < c[t[2 * i + 1]] ? t[2 * i] : t[2 * i + 1];
}

int get(int t[], int c[], int i, int cl, int cr, int l, int r)
{
	if (cl == l && cr == r) return t[i];
	if (l > (cl + cr) / 2)
		return get(t, c, 2 * i + 1, (cl + cr) / 2 + 1, cr, l, r);
	if (r <= (cl + cr) / 2)
		return get(t, c, 2 * i, cl, (cl + cr) / 2, l, r);

	int A = get(t, c, 2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2);
	int B = get(t, c, 2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r);

	return c[A] <= c[B] ? A : B;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; i ++)
		if (s[i] == '?')
			m ++, pos[m] = i, used[i] = true;
	for (int i = 1; i <= m; i ++)
		scanf("%d%d", &a[pos[i]], &b[pos[i]]);

	for (int i = 0; i < n; i ++)
		c[i] = d[i] = 1000000000;

	for (int i = 0; i < n; i ++)
		if (s[i] == '?')
		{
			s[i] = (a[i] <= b[i]) ? '(' : ')';
			if (a[i] <= b[i]) c[i] = b[i] - a[i]; else d[i] = a[i] - b[i];
		}

	build(t1, c, 1, 0, n - 1);
	build(t2, d, 1, 0, n - 1);

	int balanse = 0;
	for (int i = 0; i < n; i ++)
		if (s[i] == '(') balanse ++; else
			if (s[i] == ')')
			{
				balanse --;
				if (balanse < 0)
				{
					int ms = get(t2, d, 1, 0, n - 1, 0, i);
					if (d[ms] == 1000000000)
					{
						printf("-1\n");
						return 0;
					}
					s[ms] = '('; balanse += 2;
					update(t1, c, 1, 0, n - 1, ms, - d[ms]);
					update(t2, d, 1, 0, n - 1, ms, 1000000000);
				}
			}

	balanse = 0;
	for (int i = n - 1; i >= 0; i --)
		if (s[i] == ')') balanse ++; else
			if (s[i] == '(')
			{
				balanse --;
				if (balanse < 0)
				{
					int ms = get(t1, c, 1, 0, n - 1, i, n - 1);
					if (c[ms] == 1000000000)
					{
						printf("-1\n");
						return 0;
					}
					s[ms] = ')'; balanse += 2;
					update(t2, d, 1, 0, n - 1, ms, - c[ms]);
					update(t1, c, 1, 0, n - 1, ms, 1000000000);
				}
			}


	long long res = 0;
	for (int i = 0; i < n; i ++)
		if (used[i]) res += s[i] == '(' ? (long long)(a[i]) : (long long)(b[i]);
	cout << res << endl;
	puts(s);

	return 0;
}