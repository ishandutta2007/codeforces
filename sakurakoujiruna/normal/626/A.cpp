#include <iostream>
using namespace std;

const int N = 120011;
int cnt[N * 2];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	cin >> str;

	int acc = 0;
	cnt[acc + N] ++;

	int ans = 0;
	for(auto &c : str)
	{
		if(c == 'U')
			acc ++;
		else if(c == 'D')
			acc --;
		else if(c =='L')
			acc += 500;
		else
			acc -= 500;
		ans += cnt[acc + N];
		cnt[acc + N] ++;
	}
	cout << ans << '\n';
	return 0;
}