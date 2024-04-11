#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<double, double> PDD;

const int maxlongint = 2147483647;
const int biglongint = 2139062143;
#define LL long long
#define w1 first
#define w2 second
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

int main()
{
	int k, n, w;
	scanf("%d %d %d", &k, &n, &w);
	cout << max((LL)0, (LL)w * (w + 1) / 2 * k - n) << endl;
	return 0;
}