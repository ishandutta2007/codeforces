#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        int csum = 0;
        bool has0 = false;
        bool has2 = false;
        for (int j = 0; j < s.length(); j++)
        {
            int d = s[j] - '0';
            csum += d;
            if (!has0 && d == 0)
                has0 = true;
            else if (!has2 && d % 2 == 0)
                has2 = true;
        }
        if (has0 && has2 && (csum % 3 == 0))
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}