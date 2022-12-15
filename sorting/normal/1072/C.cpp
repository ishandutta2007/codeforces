#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;

bool used[N];
vector<long long> res_a, res_b;

int main ()
{
	long long a, b;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	long long i;

	for(i = 0; (i+1)*(i+2)/2 <= a+b; i++)
		continue;

	//cout << i << endl;

	for(long long j = i; j >= 1; j--)
		if(a >= j)
		{
			a -= j;
			used[j] = true;
		}

	for(long long j = 1; j <= i; j++)
		if(used[j])
			res_a.push_back(j);
		else
			res_b.push_back(j);

	long long cnt_a = 0, cnt_b = 0;

	if(!res_a.empty())
		cnt_a  = res_a.size();
	if(!res_b.empty())
		cnt_b = res_b.size();

	cout << cnt_a << "\n";

	for(long long j = 0; j < cnt_a; j++)
		cout << res_a[j] << " ";
	cout << "\n";

	cout << cnt_b << "\n";

	for(long long j = 0; j < cnt_b; j++)
		cout << res_b[j] << " ";
	cout << "\n";

	return 0;
}