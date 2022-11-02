#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<double, double> PDD;

const int maxlongint = 2147483647;
const int biglongint = 2139062143;

#define w1 first
#define w2 second
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

int main()
{
	string st;
	cin >> st;
	st += "+";
	vector<int> ans;
	ans.clear();
	int e = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '+')
		{
			ans.p_b(e);
			e = 0;
		}
		else
			e = e * 10 + st[i] - '0';
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0) cout << "+";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}