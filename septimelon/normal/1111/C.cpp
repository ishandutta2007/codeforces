#include <bits/stdc++.h>

using namespace std;

long long n, k, A, B;
long long num = 0, sum = 0;
long long u;
long long nu;

class lennu
{
public:
    long long su, nu;
    lennu (long long su1 = 0, long long nu1 = 0): su(su1), nu(nu1) {};
};

lennu check(vector<int>& v1, int beg, int leng)
{
    if (leng > 1)
    {
        lennu lenl(A, 0);
        if (u < 0 || v1[u] < beg + leng/2)
            lenl = check(v1, beg, leng/2);
        lennu lenr(A, 0);
        if (u < 0 || v1[u] < beg + leng)
            lenr = check(v1, beg+leng/2, leng/2);
        lennu lenf(0, lenl.nu + lenr.nu);
        if (lenf.nu == 0)
            lenf.su = A;
        else if (lenl.nu != 0 && lenr.nu != 0)
            lenf.su = lenl.su + lenr.su;
        else if (B * lenf.nu * leng < lenl.su + lenr.su)
            lenf.su = B * lenf.nu * leng;
        else lenf.su = lenl.su + lenr.su;
        //cout << "b " << beg << " l " << leng << " lennu " << lenf.su << " " << lenf.nu << endl;
        return lenf;
    }
    else
    {
        nu = 0;
        while (u >= 0 && v1[u] == beg)
        {
            nu++;
            u--;
        }
        lennu lenf(B * nu, nu);
        if (lenf.nu == 0)
            lenf.su = A;
        //cout << "b " << beg << " l " << leng << " lennu " << lenf.su << " " << lenf.nu << endl;
        return lenf;
    }
}

int main()
{
    cin >> n >> k >> A >> B;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    sort (a.rbegin(), a.rend());
    u = k-1;
    int uk = 1;
    int len = 1;
    for (int i = 0; i < n; i++)
        len *= 2;
    /*for (int i = 0; i < k; i++)
        cout << a[i] <<  " ";*/
    lennu lenna = check(a, 1, len);
    cout << lenna.su << endl;
    return 0;
}