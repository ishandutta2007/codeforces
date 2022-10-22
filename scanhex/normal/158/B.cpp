#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
using namespace std;
int main() 
{                  
	int n;
	cin >> n;
	int cnt[5]; 
	for (int i = 0; i < 5; ++i) cnt[i] = 0;
	for (int i = 0; i < n; ++i)
	{                                                               
		int c;
		cin >> c;                                      
		++cnt[c];	
	}                                                   	  
	int ans = 0;
	int m = min(cnt[1], cnt[3]);
	ans += m;
	ans += cnt[4];
	cnt[1] -= m;
	cnt[3] -= m;
	ans += cnt[2] / 2;
	cnt[2] -= cnt[2] / 2 * 2;
	if (cnt[3] > 0)
	{
		ans += cnt[3];
		cnt[3] = 0;
	}  
	ans += cnt[1] / 4;
	cnt[1] = cnt[1] % 4;
	if (cnt[1] + 2 * cnt[2] > 0 && cnt[1] + 2 * cnt[2] <= 4)
		ans += 1;
	if (cnt[1] + 2 * cnt[2] > 4)
		ans += 2;
	cout << ans;
}