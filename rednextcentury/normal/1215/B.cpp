#include <bits/stdc++.h>
#define in_arr(n,A)                     for(int i=0;i<n;i++)cin>>A[i];
#define IOS                             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi                              vector <int>
#define vl                              vector <ll>
#define out_arr(n,A)                    for(int i=0;i<n;i++)cout<<A[i]<<" ";
#define LINE                            cout << endl
#define SPACE                           cout << " "
#define pb                              push_back
#define Fr                              first
#define Sc                              second
#define YES                             cout << "YES"
#define NO                              cout << "NO"
#define wrong                           cout << -1
#define pll                             pair <ll, ll>
#define pii                             pair <int, int>
#define int                             ll
#define OO                              1e18
#define SMALL                           INT_MIN
#define BIGx2                           LONG_LONG_MAX
#define sz                              size()
//BIT_OP
#define isOn(s, j)                      (s & (1<<j))
#define setBit(s, j)                    (s |= ( 1<< j))
#define clearBit(s, j)                  (s &= ~( 1 << j ))
#define lowBit(s)                       (s & (-s))
#define setAll(s, n)                    ( s = ( 1 << n ) - 1)
#define modulo(s, n)                    ((s) & ( n - 1 ))
#define isPowerOfTwo(s)                 (!(s & (s - 1)))
#define nearestPowerOfTwo(s)            ((int)pow(2.0, (int)((log((double)s) / log(2.0)) + 50. )))
#define nextnearestPowerOfTwo(s)        (1<<(32 - __builtin_clz(s)))
#define turnoffLastBit(s)               ((s) & (s - 1))
#define turnonLastZero(s)               ((S) | (s + 1))
#define turnoffLastConsecutiveBits(s)   ((s) & (s + 1))
#define Range                           pair<pair<int, int>, int>
typedef long long ll;
using namespace std;
int n;
ll Dp[200200][2];
int A[200200];
ll Rec(int i, int Cnt)
{
    if(i == n)
        return Cnt;
    if(Dp[i][Cnt] != -1)
        return Dp[i][Cnt];
    ll P = 0, L = Cnt;
    if(A[i] > 0)
    {
        P = Rec(i+1,Cnt);
    }
    else
    {
        P = Rec(i+1,1-Cnt);
    }
    return Dp[i][Cnt] = (P + L);
}
int32_t main()
{
    IOS
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    memset(Dp, -1, sizeof(Dp));
    ll ret = 0;
    for (int i=0;i<n;i++)ret+=Rec(i,0);
    cout << ret << " " << abs(ret - ((n * 1LL * (n + 1)) >> 1LL));

}