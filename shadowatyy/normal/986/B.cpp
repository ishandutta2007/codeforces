#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1<<20;

int n;

int a[N];

int load[2*N];

ll res;

void insert(int a)
{
	a += N;

	while(a)
	{
		++load[a];
		a /= 2;
	}
}

int query(int a, int b)
{
	if(a>b)
		return 0;

	a += N;
	b += N;

	int res = load[a];

	if(a!=b)
		res += load[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1];

		if(b%2==1)
			res += load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		res += query(a[i], n);
		insert(a[i]);
	}

	if((3*n)%2==res%2)
		cout << "Petr" << endl;
	else
		cout << "Um_nik" << endl;
}