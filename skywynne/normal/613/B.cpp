#include<bits/stdc++.h>
using namespace std;
long long n, c, p, t, k, d, l, r, mid;
long long m, Mx, PS[100010];
pair < int , int > A[100010];
pair < int , pair < int , int > > Mc;
int LR(int s)
{
    int lt = -1, rt = n;
    while (rt - lt > 1)
    {
        if (A[(lt + rt) / 2].first < s)
        {
            lt = (lt + rt) / 2;
        }
        else
        {
            rt = (lt + rt) / 2;
        }
    }
    return (rt);
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d", &n, &c, &p, &t, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    sort(A, A + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i].first == c)
        {
            d ++;
            continue;
        }
        break;
    }
    Mx = 1ll * d * p + 1ll * A[0].first * t;
    for (int i = 1; i <= n; i++)
    {
        PS[i] = PS[i - 1] + A[i - 1].first;
    }
    for (int i = 0; i <= n; i++)
    {
        k = m - (1ll * i * c - PS[n] + PS[n - i]);
        if (k < 0)
        {
            continue;
        }
        l = 0;
        r = c + 1;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            d = LR(mid);
            if (n - i < d)
            {
                d = n - i;
            }
            if (1ll * d * mid - PS[d] <= k)
            {
                l = mid;
                //cout << "1 : " << i << " : " << l << "\n";
            }
            else
            {
                r = mid;
                //cout << "2 : " << i << " : " << r << "\n";
            }
        }
        //cout << i << " : " << PS[3] << " " << l << endl;
        if (Mx < 1ll * i * p + 1ll * l * t)
        {
            Mx = 1ll * i * p + 1ll * l * t;
            Mc = make_pair(i, make_pair(l, d));
            //cout << "\nMax : " << i << " " << l << endl;
        }
    }
    printf("%I64d\n", Mx);
    //Mx = 1ll * Mc.second.first * t + 1ll * Mc.first * p;
    //printf("%I64d\n", max(Mx, Mxm));
    for (int i = 0; i < Mc.second.second; i++)
    {
        A[i].first = Mc.second.first;
    }
    for (int i = 0; i < Mc.first; i++)
    {
        A[n - i - 1].first = c;
    }
    for (int i = 0; i < n; i++)
    {
        r = A[i].first;
        A[i].first = A[i].second;
        A[i].second = r;
    }
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i].second);
    }
    return (0);
}