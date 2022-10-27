#include <iostream>
#include <cstdio>
using namespace std;
const int NICO = 200002;
int n, m;
int a[NICO];
int sum[NICO];
int main()
{
    cin >> n >> m;
    int res = 0;
    sum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int l, r;
        cin >> l >> r;
        if(sum[r] - sum[l-1] > 0) res += sum[r] - sum[l-1];
    }
    cout << res << endl;
}