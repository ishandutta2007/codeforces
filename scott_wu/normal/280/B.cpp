#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 100100;

int N;
int num[MAXN];
int q[MAXN];
int nq;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	q[0] = num[0];
	nq = 1;
	
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		while (nq > 0 && q[nq-1] < num[i])
			nq--;
		
		if (nq > 0)
			ans = max (ans, (num[i] ^ q[nq-1]));
		q[nq] = num[i];
		nq++;
	}
	
	q[0] = num[N-1];
	nq = 1;
	for (int i = 1; i < N; i++)
	{
		while (nq > 0 && q[nq-1] < num[N-1-i])
			nq--;
		
		if (nq > 0)
			ans = max (ans, (num[N-1-i] ^ q[nq-1]));
		q[nq] = num[N-1-i];
		nq++;
	}
	
	cout << ans << "\n";
	return 0;
}