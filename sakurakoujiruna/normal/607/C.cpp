#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2000011;
int p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	n -= 1;

	string sa, sb;
	cin >> sa >> sb;
	reverse(sb.begin(), sb.end());
	for(char &c : sb)
		if(c == 'W')
			c = 'E';
		else if(c == 'E')
			c = 'W';
		else if(c == 'N')
			c = 'S';
		else
			c = 'N';
	sb += sa;

	for(int i = 1; i < 2 * n; i ++)
	{
		p[i] = p[i - 1];
		while(p[i] > 0 && sb[i] != sb[p[i]])
			p[i] = p[p[i] - 1];
		if(sb[i] == sb[p[i]])
			p[i] ++;
	}
	if(p[2 * n - 1] == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}