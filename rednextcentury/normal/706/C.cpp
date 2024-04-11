#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define PB          push_back
#define PF          push_front
#define PII         pair <int,int>
#define MII         map <int,int>
#define MSI         map <string,int>
#define MIS         map <int,string>
#define MLI         map <long long int,int>
#define MIL         map <int,long long int>
typedef long long int           LL;
typedef vector <string>         VS;
typedef vector <int>            VI;
typedef vector <char>           VC;
typedef vector <LL>             VLL;
int GCD(int x, int y){ if (x%y == 0) return y; else return (GCD(y, x%y)); }
ll n, a[100100];
ll dp[100100][3];
string str1[100100], str2[100100];
ll solve(int  i, int last)
{
	ll x1 = 1e16, x2 = 1e16;
	if (i == n) return 0;
	if (dp[i][last] != -1) return dp[i][last];
	if (i == 0)
	{
		x1 = solve(i + 1, 0);
		x2 = a[i] + solve(i + 1, 1);
	}
	else if (last == 0)
	{
		if (str1[i] >= str1[i - 1])
			 x1 =  solve(i + 1, 0);
		if (str2[i] >= str1[i - 1])
             x2 = solve(i + 1, 1) + a[i];

	}
	else
	{
		if(str1[i] >= str2[i - 1])
            x1 = solve(i + 1, 0);
	   if (str2[i] >= str2[i - 1])
            x2 = solve(i + 1, 1)+a[i];
	}
	dp[i][last] = min(x1, x2);
	return min(x1, x2);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		cin >> str1[i];
		string temp = str1[i];
		reverse(temp.begin(), temp.end());
		str2[i] = temp;
	}
	memset(dp, -1, sizeof(dp));
	ll res =  solve(0, 2);
	if (res > 1e15) cout << -1;
	else
		cout << res;
	return 0;
}