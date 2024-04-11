#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int N = s.length();
    int M = 0;
    for (int i = 0; i < N; i++)
        if (s[i] == 'a')
            M++;
    cout << min (N, 2 * M - 1) << "\n";
}