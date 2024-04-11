#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

#define clr(a) memset(a, 0, sizeof(a))
#define fori(a) for(int i = 0; i < a; i++)
#define forj(a) for(int j = 0; j < a; j++)
#define ll long long

using namespace std;

set <string> S;


int main()
{
    int n, a, b, c;
    cin >> n>> a>> b>> c;
    int ans = 0;
    fori(a + 1)
        forj(b + 1)
        {
            int w = (n * 2 - i - j * 2);
            if ((w % 4 == 0) && (w >= 0) && (w / 4 <= c)) ans++;
        }
    cout << ans;



    return 0;
}