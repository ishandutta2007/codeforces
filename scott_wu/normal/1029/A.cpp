#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N, K;
    string s;
    cin >> N >> K >> s;
    int res = N - 1;
    while (res)
    {
        bool good = true;
        for (int i = 0; i < res; i++)
            if (s[i] != s[i + N - res])
                good = false;

        if (good) break;
        res--;
    }
    cout << s;
    for (int i = 1; i < K; i++)
    {
        for (int j = res; j < N; j++)
            cout << s[j];
    }
    cout << "\n";
}