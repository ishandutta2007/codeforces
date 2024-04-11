#include <bits/stdc++.h>
using namespace std;

//counts 0 as valid.
long long ltknz(int k, int len)
{
    long long ret = 0;
    if(k == -1) return ret;
    ret++;
    if(k == 0) return ret;
    ret += 9*len;
    if(k == 1) return ret;
    ret += 9*9*(((len)*(len - 1))/2);
    if(k == 2) return ret;
    ret += (9*9*9*len*(len - 1)*(len - 2))/6;
    return ret;
}

long long num(long long n)
{
    if(n == 0) return 0;
    long long tot = 0;
    string s = to_string(n);
    int d = s.length();
    for(int fdd = 0; fdd < d; fdd++)
    {
        int nz = 0;
        for(int i = 0; i < fdd; i++) if(s[i] != '0') nz++;
        if(nz > 3) break;
        int dig = s[fdd] - '0';
        if(dig == 0) continue;
        tot += (dig - 1)*ltknz(2 - nz, d - fdd - 1);
        tot += ltknz(3 - nz, d - fdd - 1);
        if(fdd == 0) tot--;
    }
    int nz = 0;
    for(int i = 0; i < d; i++) if(s[i] != '0') nz++;
    if(nz <= 3) tot++;
    return tot;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long l, r;
        cin >> l >> r;
        cout << num(r) - num(l - 1) << endl;
    }
}