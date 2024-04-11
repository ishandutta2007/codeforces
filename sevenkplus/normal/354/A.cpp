#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010
#define INF 1000000000000000000LL

int n; 
ll l, r, ql, qr; 
ll a[N];
ll s[N];

int main()
{
    cin >> n >> l >> r >> ql >> qr;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    
    s[0] = 0;
    for (int i = 0; i < n; i ++)
        s[i+1] = s[i] + a[i];
    
    ll S = INF;
    
    for (int i = 0; i <= n; i ++)
    {
        ll T = 0;
        T += s[i] * l;
        T += (s[n] - s[i]) * r;
        if (i < n-i)
            T += qr * (n-i-i-1);
        else if (i > n-i)
            T += ql * (i-(n-i)-1);
        S = min(S, T);
    }
    
    cout << S << endl;
    return 0;
}