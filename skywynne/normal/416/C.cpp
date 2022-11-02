#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n, k, r, c;
pair < int , pair < int , int > > A[1010];
set < pair < int , int > > S;
set < pair < int , int > > :: iterator it;
vector < pair < int , int > > V;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i].s.f >> A[i].f;
        A[i].s.s = i;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> r;
        S.insert(make_pair(r, i));
    }
    sort(A + 1, A +  n + 1);
    reverse(A + 1, A +  n + 1);
    for (int i = 1; i <= n; i++)
    {
        it = S.upper_bound(make_pair(A[i].s.f, 0));
        if (it == S.end())
        {
            continue;
        }
        c += A[i].f;
        V.push_back(make_pair(A[i].s.s, (*it).s));
        S.erase(it);
    }
    cout << V.size() << " " << c << "\n";
    for (int i = 0 ; i < (int)V.size(); i++)
    {
        cout << V[i].f << " " << V[i].s << "\n";
    }
    return (0);
}