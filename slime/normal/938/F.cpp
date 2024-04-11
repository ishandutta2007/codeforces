#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 5005
#define ld long double
using namespace std;
char inp[maxn];
bool flag[maxn];
bool nf[maxn];
bool can[27];
int main()
{
	scanf("%s", inp + 1);
	int n = strlen(inp + 1);
	int tot = 0;
	for(int i = 1; (1 << i) <= n; i++)
		tot += (1 << (i - 1));
	nf[0] = 1;
//	cout<<tot<<endl;
//	cout<<mxs<<endl;
	for(int i = 1; i <= n - tot; i++)
	{
		for(int i = 0; i <= tot; i++)
			flag[i] = nf[i];
		memset(can, 0, sizeof(can));
		for(int i = 1; i <= tot; i <<= 1)
		{
			for(int j = 0; j <= tot; j += (i << 1))
				for(int k = j; k < i + j; k++)
					flag[i + k] |= flag[k];
		//	cout<<i<<" "<<flag[2]<<endl;
		//	if(i == ) 
		}
		//cout<<flag[6]<<endl;
		for(int j = i; j <= n; j++)
			if(flag[j - i]) 
				can[inp[j] - 'a'] = 1;//, cout<<"CAN"<<j<<" "<<inp[j] - 'a'<<endl;
		for(int i = 0; i <= tot; i++)
			nf[i] = 0;
		for(int j = 0; j < 27; j++)
			if(can[j])
			{
				for(int t = i; t <= n; t++)
					if(inp[t] == j + 'a' && flag[t - i])
						nf[t - i] = 1;//, cout<<"CAN"<<i<<" "<<t<<endl;
				printf("%c", char(j + 'a'));
				break;
			}
	//	cout<<"AFT"<<i<<endl;
	}
	return 0;
}
/*
9
1 1 1 1 1 1 1 1 1
-8 -1 -2 -4 -4 -2 -3 -4 -5
1 2
1 3
1 4
1 5
5 6
4 7
3 8
2 9

*/