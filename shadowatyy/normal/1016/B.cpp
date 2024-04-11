#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1e3+7;

int n, m, q;

string s, t;

int ile[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q >> s >> t;

	for(int i = 0; i < n; ++i)
	{
		if(s.substr(i, t.size())==t)
			++ile[i+1];

		ile[i+2] += ile[i+1];
	}

	while(q--)
	{
		int a, b;
		cin >> a >> b;

		if(t.size()<=b-a+1)
			cout << ile[b-t.size()+1]-ile[a-1] << endl;
		else
			cout << 0 << endl;
	}
}