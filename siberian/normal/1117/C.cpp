 #include <bits/stdc++.h>

using namespace std;

#define int long long
int x1, Y1, x2, y2;
int n;
string s;
void read()
{
	cin >> x1 >> Y1 >> x2 >> y2;
	cin >> n;
	cin >> s;
}
int ans;
int cntU = 0, cntD = 0, cntL = 0, cntR = 0;
	
bool check(int t)
{
	int U = 0, D = 0, L = 0, R = 0;
	U += cntU * (t/n);
	D += cntD * (t/n);
	L += cntL * (t/n);
	R += cntR * (t/n);
	for (int i = 0; i < t % n; i++)
	{
		if (s[i] == 'U') U++;
		if (s[i] == 'D') D++;
		if (s[i] == 'L') L++;
		if (s[i] == 'R') R++;	
	}
	int dx = x2 - x1;
	int dy = y2 - Y1;
	
	int maxY = U - D;
	int maxX = R - L;

//	cout << R << " " << L << " " << D << " " << U << endl;
//	cout << dx << " " << minX << " " << maxX << " " << dy << " " << minY << " " << maxY << endl; 
	dx -= maxX;
	dy -= maxY;
	return abs(dx) + abs(dy) <= t;
}

void run()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'U') cntU++;
		if (s[i] == 'D') cntD++;
		if (s[i] == 'L') cntL++;
		if (s[i] == 'R') cntR++;
	}

	int l = 0, r = 1e18, mid;
	while (l < r - 1)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}	
	ans = r;
	if (ans == 1e18)
		ans = -1;
}

void write()
{
	cout << ans << endl;
//	cout << "lksfnv   " << check(4) << endl; 
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}