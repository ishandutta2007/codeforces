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
#define OO                              INT_MAX
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
#define _CRT_SECURE_NO_WARNINGS
typedef long long ll;
using namespace std;
pair<ll, ll> Tree[200200 << 2];
ll Lazy[200200 << 2];
ll A[202020];
ll n, T;
void Build(ll Now, ll Start, ll End)
{
    if(Start == End)
    {
        Tree[Now].Fr = A[Start];
        Tree[Now].Sc = A[Start];
        return;
    }
    ll Mid = Start + End >> 1;
    Build(Now << 1, Start, Mid);
    Build(Now << 1 | 1, Mid + 1, End);
    Tree[Now].Fr = (Tree[Now << 1].Fr + Tree[Now << 1 | 1].Fr);
    Tree[Now].Sc = max(Tree[Now << 1].Sc, Tree[Now << 1 | 1].Sc);
}
 
ll Query(ll i, ll j, ll Now, ll Start, ll End)
{
    if(End < i || Start > j)
        return 0;
    if(Start >= i && End <= j)
        return Tree[Now].Fr;
 
    ll Mid = Start + End >> 1;
    ll TryLeft = Query(i, j, Now << 1, Start, Mid);
    ll TryRight = Query(i, j, Now << 1 | 1, Mid + 1, End);
    return (TryLeft + TryRight);
}
void PointUpdate(ll i, ll j, ll Now, ll Start, ll End, ll Val)
{
 
    if(End < i || Start > j) return ;
    if(Start == End)
    {
        Tree[Now].Sc = Val;
        Tree[Now].Fr = Tree[Now].Sc;
        return ;
    }
    ll Mid = Start + End >> 1;
    PointUpdate(i, j, Now << 1, Start, Mid, Val);
    PointUpdate(i, j, Now << 1 | 1, Mid + 1, End, Val);
    Tree[Now].Sc = max(Tree[Now << 1].Sc, Tree[Now << 1 | 1].Sc);
    Tree[Now].Fr = (Tree[Now << 1].Fr + Tree[Now << 1 | 1].Fr);
}
void RangeUpdate(ll i, ll j, ll Now, ll Start, ll End, ll Val)
{
    if(End < i || Start > j || Tree[Now].Sc < Val)
        return ;
    if(Start == End)
    {
        Tree[Now].Sc %= Val;
        Tree[Now].Fr %= Val;
        return;
    }
    ll Mid = Start + End >> 1;
    RangeUpdate(i, j, Now << 1, Start, Mid, Val);
    RangeUpdate(i, j, Now << 1 | 1, Mid + 1, End, Val);
    Tree[Now].Fr = (Tree[Now << 1].Fr + Tree[Now << 1 | 1].Fr);
    Tree[Now].Sc = max(Tree[Now << 1].Sc, Tree[Now << 1 | 1].Sc);
}
int main()
{
    IOS
    cin >> n >> T;
    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    Build(1, 0, n - 1);
    while(T--)
    {
        ll k;
        cin >> k;
        if(k == 1)
        {
            ll Left, Right;
            cin >> Left >> Right;
            Left--;
            Right--;
            cout << Query(Left, Right, 1, 0, n - 1) << endl;
        }
        else if(k == 2)
        {
            ll Left, Right, x;
            cin >> Left >> Right >> x;
            Left--;
            Right--;
            RangeUpdate(Left, Right, 1, 0, n - 1, x);
            // cout << Query(0, n - 1, 1, 0, n - 1) << endl;
        }
        else
        {
            ll kk, x;
            cin >> kk >> x;
            kk--;
            PointUpdate(kk, kk, 1, 0, n - 1, x);
            //cout << Query(0, n - 1, 1, 0, n - 1) << endl;
        }
    }
   /// cout << "warghsdarghghgh";
}