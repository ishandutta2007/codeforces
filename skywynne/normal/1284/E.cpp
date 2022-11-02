// In The Name Of The Queen
#include<bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;
typedef long double ld;
typedef complex < ld > point;
const int N = 2505;
const ld PI = acos((ld)-1.0);
int n, m, FENL, F[N + 100];
point A[N];
ld Ang[N];
inline bool CMP(int i, int j)
{
    return (Ang[i] < Ang[j]);
}
inline void Add(int i, int val)
{
    for (i += 5; i < FENL; i += i & - i)
        F[i] += val;
}
inline int Get(int i)
{
    int rt = 0;
    for (i += 5; i; i -= i & - i)
        rt += F[i];
    return (rt);
}
inline bool Okay(int j, int h)
{
    ld ang = Ang[j] - PI;
    while (ang < 0.0)
        ang += PI * 2.0;
    return (Ang[h] > ang);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int aa, bb;
        cin >> aa >> bb;
        aa += (int)(1e9 + 10);
        bb += (int)(1e9 + 10);
        A[i] = point((ld)aa, (ld)bb);
    }
    point qp = polar((ld)1.0, (ld)0.532);
    for (int i = 1; i <= n; i ++)
        A[i] = A[i] * qp;
    long long tot = 0;
    for (int i = 1; i <= n; i ++)
    {
        vector < int > vec, vet;
        vector < ld > U;
        for (int j = 1; j <= n; j ++)
        {
            if (i == j)
                continue;
            if (A[j].x > A[i].x)
            {
                vec.push_back(j);
                U.push_back(A[j].x);
                Ang[j] = arg(A[j] - A[i]);
            }
            else
            {
                Ang[j] = arg(A[j] - A[i]);
                while (Ang[j] < 0)
                    Ang[j] += PI * 2.0;
                vet.push_back(j);
            }
        }
        sort(vet.begin(), vet.end(), CMP);
        sort(vec.begin(), vec.end(), CMP);
        sort(U.begin(), U.end());
        FENL = (int)vec.size() + 10;
        int ptr = 0;
        for (int h = 0; h < (int)vec.size(); h ++)
        {
            int j = vec[h];
            while (ptr < (int)vet.size() && !Okay(j, vet[ptr]))
                ptr ++;
            int xx = (int)(lower_bound(U.begin(), U.end(), A[j].x) - U.begin());
            int rt = Get(xx - 1);
            Add(xx, 1);
            tot += 1LL * rt * (h - ((int)vec.size() - h - 1));
            tot += 1LL * rt * ((int)vet.size() - ptr - ptr);
            tot -= rt;
        }
        for (int h = 0; h < FENL; h ++)
            F[h] = 0;
    }
    tot *= (n - 4);
    tot /= 2;
    cout << tot << "\n";
    return 0;
}