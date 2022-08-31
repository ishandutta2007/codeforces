#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
char o[2][maxn];
int ls[2];
char ns[2][maxn];
struct work
{
	char inp[2][maxn];
	int l[2];
	int mv[maxn][2], mvcnt; 
	int tp[2], pl[2];
	int pls[2][maxn], plcnt[2];
	void sw(int x, int y)
	{
		int pl[2] = {x, y};
		int nl[2] = {0, 0};
		for(int i = 0; i < 2; i++)
		{
			for(int j = 1; j <= pl[i ^ 1]; j++)
				ns[i][++nl[i]] = inp[i ^ 1][j];
			for(int j = pl[i] + 1; j <= l[i]; j++)
				ns[i][++nl[i]] = inp[i][j];
		}
		for(int i = 0; i < 2; i++)
		{
			l[i] = nl[i];
			for(int j = 1; j <= nl[i]; j++)
				inp[i][j] = ns[i][j];
		}
	}
	void cal()
	{
		for(int i = 0; i < 2; i++)
		{
			l[i] = ls[i];
			for(int j = 1; j <= l[i]; j++)
				inp[i][j] = o[i][j];
			inp[i][++l[i]] = 'a' + i;
		}
		memset(plcnt, 0, sizeof(plcnt));
		memset(pls, 0, sizeof(pls));
		mvcnt = 0;
		for(int i = 0; i < 2; i++)
			for(int j = 1; j < l[i]; j++)
				if(inp[i][j] != inp[i][j + 1])
					if(inp[i][j] != 'a' + i)
						pls[i][plcnt[i]++] = j;
		if(plcnt[0] == 0 && plcnt[1] == 0)
			return ;
		int s[2] = {plcnt[0] / 2, plcnt[1] / 2};
		int tt[2] = {plcnt[0] * 2, plcnt[1] * 2};
		int gv[2] = {s[0] * 2 + 2, s[1] * 2 + 2};
		if(inp[0][1] == 'b') tt[0]--, gv[0]--;
		if(inp[1][1] == 'a') tt[1]--, gv[1]--;
		if(plcnt[0] == 0) gv[0] = 0;
		if(plcnt[1] == 0) gv[1] = 0;
		int lst[2] = {tt[0] - gv[0] + gv[1], tt[1] - gv[1] + gv[0]};
	//	cout<<lst[0]<<" "<<lst[1]<<endl; 
		for(int i = 0; i < 2; i++)
		{
			if(lst[i] >= lst[i ^ 1] + 2)
			{
				if(s[i ^ 1]) s[i ^ 1]--;
				else if(s[i] < plcnt[i] - 1) s[i]++;
			//	cout<<"ASFD"<<endl;
				break;
			}
		}
		int xs = pls[0][s[0]], ys = pls[1][s[1]];
 	//	cout<<xs<<" "<<ys<<" "<<l[0]<<" "<<" "<<l[1]<<endl;
		sw(xs, ys);
	//	cout<<"WAR"<<" "<<l[0]<<" "<<l[1]<<endl;
	//	cout<<inp[0] + 1<<" "<<inp[1] + 1<<endl;
	//	while(1); 
		mv[mvcnt][0] = xs, 
		mv[mvcnt++][1] = ys;
		tp[0] = 0, tp[1] = 1;
		pl[0] = l[0], pl[1] = l[1];
		while(pl[0] || pl[1])
		{
		//	cout<<pl[0]<<" "<<pl[1]<<endl;
			while(pl[0] && inp[tp[0]][pl[0]] == 'a') pl[0]--;
			while(pl[1] && inp[tp[1]][pl[1]] == 'b') pl[1]--;
			if(!pl[0] && !pl[1]) break;
			mv[mvcnt][0] = pl[0], mv[mvcnt++][1] = pl[1];
			swap(pl[0], pl[1]), 
			swap(tp[0], tp[1]);
		}
	//	while(1);
	}
	void otp(int tp)
	{
		printf("%d\n", mvcnt);
		for(int i = 0; i < mvcnt; i++)
			printf("%d %d\n", mv[i][tp], mv[i][tp ^ 1]);
	}
}ans[2];
int main()
{
	scanf("%s", o[0] + 1);
	scanf("%s", o[1] + 1);
	ls[0] = strlen(o[0] + 1), 
	ls[1] = strlen(o[1] + 1);
	ans[0].cal();
	for(int i = 1; i <= max(ls[0], ls[1]); i++)
		swap(o[0][i], o[1][i]);
	swap(ls[0], ls[1]);
	ans[1].cal();
	if(ans[0].mvcnt < ans[1].mvcnt) ans[0].otp(0);
	else ans[1].otp(1);
	return 0;
} 
/*
bbbbbb
bababa

*/