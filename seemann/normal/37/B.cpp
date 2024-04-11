#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct sv{
	int pow, dmg, num;
};

int n, reg, mx, now;

bool _less(sv a, sv b)
{
	if (((now * 100 / mx < a.pow) || (now * 100 % mx == 0 && now * 100 / mx == a.pow))&&((now * 100 / mx < b.pow) || (now * 100 % mx == 0 && now * 100 / mx == b.pow)))
		{
			return a.dmg > b.dmg;
		}
	if (((now * 100 / mx < a.pow) || (now * 100 % mx == 0 && now * 100 / mx == a.pow))) return true;
	if (((now * 100 / mx < b.pow) || (now * 100 % mx == 0 && now * 100 / mx == b.pow))) return false;
	return a.dmg > b.dmg;

}

int main()
{
	cin >> n;
	sv s[1002];
	cin >> mx >> reg;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].pow >> s[i].dmg;
		s[i].num = i + 1;
		if (s[i].pow == 100) sum += s[i].dmg;
	}
	if (sum <= reg)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	now = mx;
	int i = 0;
	int sec = 0;
	sum = 0;
	int ans[1000][2];
	int c_ans = 0;
	while (now > 0)
	{
		now = min((now - sum + reg), mx);
		if (now <= 0) {sec++;break;}

		sort(s + i, s + n, _less);
		if ((now * 100 / mx < s[i].pow) || (now * 100 % mx == 0 && now * 100 / mx == s[i].pow))
		{
			sum += s[i].dmg;
			ans[c_ans][0] = sec;
			ans[c_ans++][1] = s[i].num;
			i++;
		}
		sec++;
		
	}
	sec--;
	cout << sec << " " << c_ans << '\n';
	for (int i = 0; i < c_ans; i++)
		cout << ans[i][0] << " " << ans[i][1] << '\n';


	return 0;


}