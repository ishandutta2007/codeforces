#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N, H, A, B, K;

int main()
{
    cin >> N >> H >> A >> B >> K;
    for (int i = 0; i < K; i++)
    {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        int res = abs (fa - fb) + abs (ta - tb);
        if (ta != tb && fa > B && fb > B)
            res += min (fa - B, fb - B) * 2;
        if (ta != tb && fa < A && fb < A)
            res += min (A - fa, A - fb) * 2;
        cout << res << "\n";
    }
}