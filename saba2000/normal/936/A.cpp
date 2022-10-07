#include<bits/stdc++.h>
#define psi  pair < string ,int>
#define fi first
#define se second
#define pb push_back
#define sz size
using namespace std;
map<psi ,vector<psi > >  v;
map<psi , int > D;
set<string> S;
main()
{
    long long k,d,t;
    cin >> k >> d >> t;
    t*=2;
    long long T = k-k% d;
    while (T < k) T += d;
    T -= k;
    long long O = 2*k + T;
    long long Z = t/O;
    t -= Z*O;
    if (t <= 2*k) printf("%.9f",Z*(k+T)+(double)t/2);
    else printf("%.9f",(double)Z*(k+T)+k+(t-2*k));
}