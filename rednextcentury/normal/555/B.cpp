#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ios>
using namespace std;

long long ret[1000000];
struct di
{
    long long idx;
    long long dif;
    long long len;
};
bool operator<(di a, di b)
{
    if (a.dif == b.dif)
        return a.len < b.len;
    else
        return a.dif < b.dif;
}
di a[1000000];
long long l[1000000];
long long r[1000000];
long long b[1000000];
bool comp(long long p, long long q)
{
    return p > q;
}
struct ko
{
    long long len;
    long long idx;
};
bool operator<(ko p,ko q)
{
    return p.len<q.len;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        if (i > 0)
        {
            a[i - 1].idx = i - 1;
            a[i - 1].dif = l[i] - r[i - 1];
            a[i - 1].len = r[i] - l[i-1];
        }
    }
    sort(a, a + n-1);
    multiset<ko> s;
    s.clear();
    for (long long i = 0; i < m; i++)
    {
        cin >> b[i];
        ko x;
        x.idx=i+1;
        x.len=b[i];
        s.insert(x);
    }
    if (m < n - 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (long long i = n-2; i>=0 ; i--)
    {
        ko g;
        g.idx=0;
        g.len=a[i].len+1;
        multiset<ko>::iterator it = s.lower_bound(g);
        if (it!=s.begin())
        it--;
        long long h=it->len;
        if (h < a[i].dif || h>a[i].len)
        {
            cout << "No" << endl;
            return 0;
        }
        ret[a[i].idx] = it->idx;
        s.erase(it);
    }
    cout << "Yes" << endl;
    for (long long i = 0; i < n-1; i++)
        cout << ret[i] << " ";

}