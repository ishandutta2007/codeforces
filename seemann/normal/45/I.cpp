#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
//#include <>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

int n;
int a[1000];
int main()
{
    cin >> n;
    FOR(i, n)
        cin >> a[i];
    int ans = 1;
    int i = n - 1;
    bool ind = false;
    sort(a, a + n);
    while(i >= 0 && a[i] > 0)
    {
        cout << a[i] << ' ';
        ind = true;
        i--;
    }
    i = 0;
    while (i < n && a[i] < 0)
        i++;
    for (int j = 0; j < i - (i % 2); j++)
    {
        cout << a[j] << ' ';
        ind = true;
    }
    if (! ind) cout << a[n - 1];


    return 0;
}