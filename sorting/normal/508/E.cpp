#include<bits/stdc++.h>

using namespace std;

const int N = 600 + 7;

int n;
pair<int, int> p[N];

bool dp[N][N], b[N][N];
int whatToDo[N][N];

string s;

void build(int l, int r, int bef)
{
	if(l > r)
		return;

	s[bef + (whatToDo[l][r])*2 + 1] = ')';

	build(l+1, whatToDo[l][r]+l, bef + 1);
	build(whatToDo[l][r]+1+l, r, bef + 2 + whatToDo[l][r]*2);
}

int solve(int l, int r)
{
	if(l > r)
		return 1;

	if(b[l][r])
		return dp[l][r];

	b[l][r] = 1;

	//cout << l << " enter " << r << endl;

	for(int i = 0; i <= r-l; i++)
		if(p[l].first <= (i*2 + 1)  &&  (i*2 + 1) <= p[l].second)
		{
			//cout << l+1 << " " << i+l << " " << i+1+l << " " << r << endl;
			if(solve(l+1,i+l) && solve(i+1+l, r))
			{
				dp[l][r] = 1;
				whatToDo[l][r] = i;

				//cout << l << " " << r << "\n";
				//cout << whatToDo[l][r] << " what \n";

				return 1;
			}
		}

	dp[l][r] = 0;

	return 0;
}

int main ()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	if(!solve(0, n-1))
	{
		cout << "IMPOSSIBLE\n";

		return 0;
	}

	for(int i = 0; i < 2*n; i++)
		s += "(";

	build(0, n-1, 0);

	cout << s << "\n";

	return 0;
}