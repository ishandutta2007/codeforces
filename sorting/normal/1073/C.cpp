#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

string s;

int n;
int x, y, x2, y2;

bool possible(int curr_x, int curr_y, int cnt)
{
	if(abs(curr_x-x) + abs(curr_y-y) <= cnt)
		return 1;

	return 0;
}

bool check(int mid)
{
	int curr_x = 0, curr_y = 0;

	for(int i = 0; i < mid; i++)
	{
		if(s[i] == 'U')
			curr_y++;
		if(s[i] == 'D')
			curr_y--;
		if(s[i] == 'R')
			curr_x++;
		if(s[i] == 'L')
			curr_x--;
	}


	if(possible(x2-curr_x, y2-curr_y, mid))
		return 1;

	if(mid == 0)
		return 0;

	for(int i = mid; i < n; i++)
	{
		if(s[i-mid] == 'U')
			curr_y--;
		if(s[i-mid] == 'D')
			curr_y++;
		if(s[i-mid] == 'R')
			curr_x--;
		if(s[i-mid] == 'L')
			curr_x++;

		if(s[i] == 'U')
			curr_y++;
		if(s[i] == 'D')
			curr_y--;
		if(s[i] == 'R')
			curr_x++;
		if(s[i] == 'L')
			curr_x--;

		if(possible(x2-curr_x, y2-curr_y, mid))
			return 1;
	}

	return 0;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	cin >> x >> y;

	if(abs(x) + abs(y) > n || (abs(x)+abs(y)-n) % 2 != 0)
	{
		cout << "-1\n";

		return 0;
	}

	//cout << 'h' << endl;

	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'U')
			y2++;
		if(s[i] == 'D')
			y2--;
		if(s[i] == 'R')
			x2++;
		if(s[i] == 'L')
			x2--;
	}

	int l = 0, r = n, mid;

	if(!check(n))
	{
		cout << "-1\n";

		return 0;
	}

	while(l != r)
	{
		mid = (l+r) / 2;

		if(check(mid))
			r = mid;
		else
			l = mid+1;
	}

	cout << l << "\n";

	return 0;
}