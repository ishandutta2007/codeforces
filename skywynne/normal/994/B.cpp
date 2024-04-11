#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, k, r, t, a, b, c, d, C[N];
long long sum, R[N];
pair < int , int > P[N];
multiset < int > S;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i].x), P[i].y = i;
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    sort(P + 1, P + n + 1);
    for (int i = 1; i <= n; i++)
        R[i] = C[i];
    for (int i = 1; i <= n && k > 0; i++)
    {
        int id = P[i].y;
        R[id] = sum + C[id];
        if (S.size() == k)
        {
            if (*S.begin() < C[id])
                sum -= *S.begin(), S.erase(S.begin()), sum += C[id], S.insert(C[id]);
        }
        if (S.size() < k)
            S.insert(C[id]), sum += C[id];
    }
    for (int i = 1;  i<= n; i++)
        printf("%lld ", R[i]);
    return (0);
}