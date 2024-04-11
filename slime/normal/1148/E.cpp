#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define vt vector<int>
#define maxn 600005
#define ll long long
#define ld double
using namespace std;
int n;
int a[maxn], b[maxn], c[maxn];
int tr[maxn];
struct th
{
	int num, id;
	bool operator < (const th &u)const
	{
		return num < u.num;
	}
}p[maxn];
int otp[maxn][3];
int cnt = 0;
void push(int i, int j, int d)
{
	c[i] -= d, c[j] += d;
	otp[cnt][0] = tr[i], 
	otp[cnt][1] = tr[j], 
	otp[cnt++][2] = d;
}
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), 
		p[i].num = a[i], 
		p[i].id = i;
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++)
		a[i] = p[i].num, tr[i] = p[i].id;
	sort(b + 1, b + n + 1);
	int pl = 1;
	for(int i = 1; i <= n; i++)
		c[i] = b[i] - a[i];
	//cout<<"A"<<endl;
	for(int i = 1; i <= n; i++)
		if(c[i] < 0)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			while(pl <= n && c[i])
			{
				if(c[pl] >= 0) 
				{
					pl++;
					continue;
				}
				int dv = min(c[i], -c[pl]);
				push(i, pl, dv);
			//	cout<<pl<<" "<<endl;
				if(c[pl] == 0) pl++;
			}
			if(c[i]) 
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	cout<<cnt<<endl;
	for(int i = 0; i < cnt; i++)
		printf("%d %d %d\n", otp[i][0], otp[i][1], otp[i][2]);
	return 0;
} 
/*5 100
4 1 2 3 5
3
1 2 3 6
1 1 5 1
3 2 4
*/