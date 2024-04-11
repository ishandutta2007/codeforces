#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, c, t, pot = 1;
    vector<int> costs;
    map<int, int> twolog;
    int av[32];
    memset(av, 0, sizeof(av));
    for(int i = 0; i < 32; i++)
    {
        twolog[pot] = i;
        pot <<= 1;
    }
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        //cout << c << " " << twolog[c] << endl;
        av[twolog[c]]++;
    }
    for(int i = 0; i < q; i++)
    {
        bool b = true;
        int A[32];
        memset(A, 32, sizeof(A));
        cin >> t;
        for(int j = 0; j < 32; j++)
        {
            A[j] = t%2;
            t >>= 1;
        }
        //for(int i = 31; i >= 0; i--) cout << av[i];
        //cout << endl;
        for(int j = 31; j >= 0; j--)
        {
            //for(int i = 31; i >= 0; i--) cout << A[i];
            //cout << endl;
            while(A[j] > av[j])
            {
                if(j == 0)
                {
                    b = false;
                    break;
                }
                else
                {
                    A[j]--;
                    A[j - 1] += 2;
                }
            }
        }
        int tot = 0;
        for(int i = 0; i < 32; i++)
        {
            if(A[i] > av[i]) b = false;
            tot += A[i];
        }
        if(!b) cout << -1 << endl;
        else cout << tot << endl;
    }
}