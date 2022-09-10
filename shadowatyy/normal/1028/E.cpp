#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 2e5+7;

int n, staly = 1;

int b[N];
int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	for(int i = 0; i < n; ++i)
	{
		if(b[i]!=b[(i+1)%n])
			staly = 0;
	}

	if(staly)
	{
		if(b[0]==0)
		{
			cout << "YES" << endl;

			for(int i = 0; i < n; ++i)
			{
				cout << 1 << " ";
			}

			cout << endl;
		}
		else
			cout << "NO" << endl;

		return 0;
	}

	int s = -1;

	for(int i = 0; i < n; ++i)
	{
		if(b[i]<b[(i+1)%n])
		{
			s = (i+1)%n;
			break;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		a[i] = b[i];
	}

	//cerr << s << endl;

	for(int i = 0; i < n-1; ++i)
	{
		int curr = (s-2-i+n)%n;
		
		if(a[curr]>=a[(curr+1)%n])
		{
			int chce = a[curr]-a[(curr+1)%n]+1;
			a[(curr+1)%n] += (chce+a[(curr+2)%n]-1)/a[(curr+2)%n]*a[(curr+2)%n];
		}

		if(a[(curr+1)%n]==0)
		{
			a[(curr+1)%n] += a[(curr+2)%n];
		}

		//cerr << (curr+1)%n << " " << a[(curr+1)%n] << endl;
	}

	cout << "YES" << endl;

	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}