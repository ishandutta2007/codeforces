#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long

const int INF = 1000000000;
const double EPS = 1e-8;
using namespace std;


void _kill()
{
    cout << "NO";
    exit(0);
}

int a[3];


int main()
{
    int n;
    cin >> n;
    FOR(i, n)
    {
        int w;
        cin >> w;
        a[w % 3]++;
    }
    cout << a[0] / 2 + min(a[1], a[2]);


    return 0;

}