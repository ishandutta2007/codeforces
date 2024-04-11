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
	int N, ans = 0;
	char st[10];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", st);
		if (st[1] == '-') ans--; else ans++;
	}
	cout << ans << endl;

	return 0;
}