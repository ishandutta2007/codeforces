#include<iostream>
#include<algorithm>
#define MAXN 5005
#define LL long long

using namespace std;

int n;
LL a[MAXN];
LL num[MAXN];
LL tmp;
LL ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		tmp = 0;
		num[i] = 0;
		for(int j = i+1; j <= n; j++)
		{
			num[j] = num[j-1]/a[j]+1;
			tmp += num[j];
			num[j] *= a[j];
		}
		for(int j = i-1; j >= 1; j--)
		{
			num[j] = num[j+1]/a[j]+1;
			tmp += num[j];
			num[j] *= a[j];
		}
		if(i == 1) ans = tmp;
		else ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}