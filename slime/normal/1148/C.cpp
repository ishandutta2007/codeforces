#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 300005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int a[maxn], b[maxn];
int n;
int otp[maxn * 10][2], cnt = 0;
void sw(int i, int j)
{
	otp[cnt][0] = i, otp[cnt++][1] = j;
	swap(a[i], a[j]);
	swap(b[a[i]], b[a[j]]);
}
void cal(int i, int j)
{
	if(i == j) return;
	if(i > j) swap(i, j);
	if(abs(i - j) >= n / 2) 
	{
		sw(i, j);
		return;
	}
	if(i <= n / 2) 
		if(j <= n / 2)
			sw(i, n), sw(j, n), sw(i, n);
		else
			sw(j, 1), sw(i, n), sw(1, n), sw(j, 1), sw(i, n);
	else sw(j, 1), sw(1, i), sw(j, 1);
} 

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i], b[a[i]] = i;
	for(int i = 1; i <= n; i++)
		cal(i, b[i]);
	cout<<cnt<<endl;
	for(int i = 0; i < cnt; i++)
		printf("%d %d\n", otp[i][0], otp[i][1]);
	return 0;
}