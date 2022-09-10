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
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

ll l1, r1, l2, r2, k, L, R, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> l1 >> r1 >> l2 >> r2 >> k;

    L = max(l1, l2);
    R = min(r1, r2);

    res = R-L+1;

    if(k>=L && k<=R)
    	--res;

    cout << max(res, (ll)0);



}