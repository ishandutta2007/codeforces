#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <queue>
#pragma comment ( linker, "/STACK:256000000" )

using namespace std;

struct node
{
	bool bad1, bad2;
	node * L, * R;
	node * prev;
};

int n;
int a[1100];
int num[1100];
string s[1100];

bool good = true;

void gen()
{
	node * T; T = new node;
	T->bad1 = T->bad2 = false;
	T->L = T->R = NULL;
	T->prev = NULL;
	for (int i = 1; i <= n; i ++)
	{
		int l = a[num[i]];
		node * cur = T;
		string buf = "";
		int k = 0;
		while (k < l)
		{
			if (cur->bad1 && cur->bad2) {good = false; return ;}
			if (!cur->bad1)
			{
				if (cur->L != NULL) buf += '0'; else
				{
					cur->L = new node;
					node * F = cur->L;
					F->bad1 = F->bad2 = false;
					F->L = F->R = NULL;
					F->prev = cur;
					buf += '0';
				}
				cur = cur->L;
			} else
			{
				if (cur->R != NULL) buf += '1'; else
				{
					cur->R = new node;
					node * F = cur->R;
					F->bad1 = F->bad2 = false;
					F->L = F->R = NULL;
					F->prev = cur;
					buf += '1';
				}
				cur = cur->R;
			}
			k ++;
		}
		s[num[i]] = buf;
		int f = l - 1;
		if (i == n) return ;
		int nt = a[num[i + 1]];
		while (cur->prev != NULL && f >= nt - 1)
		{
			if (buf[f] == '0') 
				cur->prev->bad1 = true; else
				cur->prev->bad2 = true;
			cur = cur->prev;
			f --;
		}
		while (cur->prev != NULL)
		{
			if (cur->bad1 && cur->bad2)
			{
				if (buf[f] == '0')
					cur->prev->bad1 = true; else
					cur->prev->bad2 = true;
			} else break;
			cur = cur->prev;
			f --;
		}
	}
}

bool comp(int x, int y)
{
	return a[x] > a[y];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), num[i] = i;

	sort(num + 1, num + n + 1, comp);
	gen();

	if (!good) printf("NO\n"); else
	{
		printf("YES\n");
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 0; j < s[i].size(); j ++)
				printf("%c", s[i][j]);
			printf("\n");
		}
	}

	return 0;
}