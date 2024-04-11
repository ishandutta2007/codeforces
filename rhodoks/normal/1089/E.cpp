#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
using pii = pair<int, int>;
const int M = 100016, MOD = 1000000007;
int a[10][10] = {{1, 1, 1, 1, 1, 1, 1, 2},
				 {2, 0, 0, 0, 0, 0, 0, 0},
				 {1, 1, 1, 1, 1, 1, 1, 2},
				 {2, 0, 0, 0, 0, 0, 0, 0},
				 {1, 1, 1, 1, 1, 1, 1, 2},
				 {2, 0, 0, 0, 0, 0, 0, 0},
				 {2, 1, 2, 1, 2, 1, 2, 1},
				 {1, 3, 1, 3, 1, 3, 1, 3}};
int b[10][10] = {{2, 2, 2, 2, 2, 2, 2, 2},
				 {2, 2, 2, 2, 2, 2, 2, 2},
				 {2, 2, 2, 2, 2, 2, 2, 2},
				 {2, 2, 2, 2, 2, 2, 2, 2},
				 {2, 2, 2, 2, 2, 2, 2, 2},
				 {2, 2, 2, 2, 2, 2, 2, 2},
				 {1, 1, 1, 1, 1, 1, 1, 1},
				 {1, 1, 1, 1, 1, 1, 1, 1}};
void print(int x, int y)
{
	printf("%c%d ", 'a' + y, x + 1);
}

pii go(int step)
{
	int x = 0, y = 0;
	print(0, 0);
	while (step--)
	{
		if (a[x][y] == 0)
			--y;
		else if (a[x][y] == 1)
			++y;
		else if (a[x][y] == 2)
			++x;
		else
			--x;
		print(x, y);
	}
	return pii(x, y);
}
int main(void)
{
	#ifdef _LITTLEFALL_
	//freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	if (n < 63)
	{
		pii p = go(n - 2);
		if (b[p.first][p.second] == 2)
			print(p.second == 7 ? p.first + 1 : 7, p.second);
		else
			print(p.first, p.first == 7 ? p.second + 1 : 7);
		print(7, 7);
	}
	else
	{
		go(n - 4);
		print(6, 7);
		print(6, 6);
		print(7, 6);
		print(7, 7);
	}


	return 0;
}