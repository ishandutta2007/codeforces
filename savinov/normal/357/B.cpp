#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    char used[n];
    memset(used, 255, sizeof(used));

    for(int i = 0; i < m; ++i)
    {
        int index[3];
        for(int j = 0; j < 3; ++j)
        {
            cin >> index[j];
            --index[j];
        }
        sort(index, index + 3);

        do
        {
            char ok = true;
            for(int j = 0; j < 3; ++j)
            {
                if (used[index[j]] != -1 && used[index[j]] != j)
                    ok = false;
            }
            if (!ok)
                continue;

            for(int j = 0; j < 3; ++j)
            {
                used[index[j]] = j;
            }
            break;

        }while(next_permutation(index, index + 3));
    }
    for(int i = 0; i < n; ++i)
    {
        if (i) cout << " ";
        cout << (int)used[i] + 1;
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}