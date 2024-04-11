#include <fstream>
#include <vector>
#include <string>
#define long long long

using namespace std;

int pow(int x, int p)
{
	int ans = 1;
	for (int i = 0; i < p; ++i)
		ans *= x;
	return ans;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, k;
	in >> n >> k;
	vector<vector<bool>> tmpl(n, vector<bool>(n));
	for (int i = 0; i < n; ++i)
	{
		string s;
		in >> s;
		for (int j = 0; j < n; ++j)
			tmpl[i][j] = s[j] == '*';
	}
	for (int i = 0; i < pow(n, k); ++i)
	{
		for (int j = 0; j < pow(n, k); ++j)
		{
			int i1 = i, j1 = j;
			bool f = false;
			int pw = pow(n, k);
			for (int p = k; p >= 1; --p)
			{
				i1 %= pw;
				j1 %= pw;
				if (tmpl[i1 / (pw / n)][j1 / (pw / n)])
				{
					f = true;
					break;
				}
				pw /= n;
			}
			out << (f ? '*' : '.');
		}
		out << endl;
	}
}