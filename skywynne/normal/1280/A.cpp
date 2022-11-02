// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006, Mod = 1e9 + 7;
int main()
{
    int q;
    cin >> q;
    for (; q; q --)
    {
        int m;
        string S;
        cin >> m >> S;
        int n = (int)S.size();
        for (int i = 0; i < m; i ++)
        {
            if (S[i] == '1')
                continue;
            if (S.size() >= m)
            {
                int k = n - i - 1;
                if (k < 0) k += Mod;
                if (S[i] == '3')
                    k = 2LL * k % Mod;
                n = (n + k) % Mod;
                continue;
            }
            string T = "";
            for (int j = i + 1; j < (int)S.size(); j ++)
                T += S[j];
            if (S[i] == '3')
                T = T + T;
            S += T;
            n = (int)S.size();
        }
        printf("%d\n", n);
    }
    return 0;
}