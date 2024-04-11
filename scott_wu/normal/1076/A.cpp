#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    string s;
    cin >> N >> s;

    int ans = N - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (s[i] > s[i+1])
            ans = i;
    }

    for (int i = 0; i < N; i++)
        if (ans != i) cout << s[i];
    cout << "\n";
}