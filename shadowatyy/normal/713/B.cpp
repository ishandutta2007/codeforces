#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

ll n, x11, y11, x12, y12, x21, y21, x22, y22, l, r, m, ans;

bool inside(ll x1, ll y1, ll x2, ll y2) // czy pierwszy prostokat zawiera sie w prostokacie z zapytania
{
	return x11>=x1 && x11<=x2 && y11>=y1 && y11<=y2 && x12>=x1 && x12<=x2 && y12>=y1 && y12<=y2;
}

ll query(ll a, ll b, ll c, ll d)
{
	cout << "? " << a << " " << b << " " << c << " " << d << endl;

	fflush(stdout);

	cin >> ans;

	return ans;
}

void answer()
{
	cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " " << x21 << " " << y21 << " " << x22 << " " << y22;

    cout << endl;

    fflush(stdout);
}

int main()
{
    cin >> n;

    x11 = 1;
    y11 = 1;
    x12 = n;
    y12 = n;
    x21 = 1;
    y21 = 1;
    x22 = n;
    y22 = n;

    l = 1, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==l)
    		++m;

    	if(query(m, y11, x12, y12))
    		l = m;
    	else
    		r = m-1;
    }

    x11 = l;

    l = 1, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==l)
    		++m;

    	if(query(x11, m, x12, y12))
    		l = m;
    	else
    		r = m-1;
    }

    y11 = l;

    l = x11, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==r)
    		--m;

    	if(query(x11, y11, m, y12))
    		r = m;
    	else
    		l = m+1;
    }

    x12 = l;

    l = y11, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==r)
    		--m;

    	if(query(x11, y11, x12, m))
    		r = m;
    	else
    		l = m+1;
    }

    y12 = l;

    //drugi

    l = 1, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==l)
    		++m;

    	if(query(m, y21, x22, y22)-inside(m, y21, x22, y22))
    		l = m;
    	else
    		r = m-1;
    }

    x21 = l;

    l = 1, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==l)
    		++m;

    	if(query(x21, m, x22, y22)-inside(x21, m, x22, y22))
    		l = m;
    	else
    		r = m-1;
    }

    y21 = l;

    l = x21, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==r)
    		--m;

    	if(query(x21, y21, m, y22)-inside(x21, y21, m, y22))
    		r = m;
    	else
    		l = m+1;
    }

    x22 = l;

    l = y21, r = n;

    while(l<r)
    {
    	m = (l+r)/2;

    	if(m==r)
    		--m;

    	if(query(x21, y21, x22, m)-inside(x21, y21, x22, m))
    		r = m;
    	else
    		l = m+1;
    }

    y22 = l;

    answer();

   	return 0;

}