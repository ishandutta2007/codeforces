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

#define int long long
const int N = 1e5+7;

int q;

ll r[N];

string pref, mid, suf;

string f(int i)
{
	if(i==0)
		return "What are you doing at the end of the world? Are you busy? Will you save us?";
	else
	{
		string p = f(i-1);
		p = char(34)+p+char(34);
		return "What are you doing while sending " + p + "? Are you busy? Will you send " + p + "?";
	}
}

char find(int n, int k)
{
	if(r[n]<k)
		return '.';

	if(n<5)
	{
		string s = f(n);
		return s[k-1];
	}
	else
	{
		if(k<=pref.size())
			return pref[k-1];
		
		if(k-pref.size()<=r[n-1])
			return find(n-1, k-pref.size());
		else if(k-pref.size()-r[n-1]<=32)
			return mid[k-pref.size()-r[n-1]-1];
		else if(k-pref.size()-r[n-1]-mid.size()<=r[n-1])
			return find(n-1, k-pref.size()-r[n-1]-mid.size());
		else
			return suf[k-pref.size()-r[n-1]-mid.size()-r[n-1]-1];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	r[0] = 75;

	for(int i = 1; i < N; ++i)
	{
		r[i] = 2*r[i-1]+68;
		r[i] = min(r[i], INF);
	}

	pref = "What are you doing while sending ";
	pref += char(34);

	mid = "? Are you busy? Will you send ";
	mid = char(34)+mid+char(34);

	suf = "?";
	suf = char(34)+suf;

	cin >> q;

	while(q--)
	{
		int n, k;
		cin >> n >> k;
		cout << find(n, k);
	}
}