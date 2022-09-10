#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

int n, b, d, a, curr, res;

int main()
{
    scanf("%d%d%d", &n, &b, &d);

    for(int i = 1; i <= n; ++i)
    {
    	cin >> a;

    	if(a>b)
    		continue;

    	curr += a;

    	if(curr>d)
    	{
    		curr = 0;
    		++res;
    	}
    }

    cout << res;
}