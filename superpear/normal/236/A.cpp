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
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int flag = 0;
		for (int i = 0; i < st.size(); i++)
			if (st[i] == c)
			{
				flag = 1;
				break;
			}
		ans += flag;
	}
	if (ans % 2 == 1)
		cout << "IGNORE HIM!" << endl;
	else
		cout << "CHAT WITH HER!" << endl;
	return 0;
}