#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<int> w(n), h(n);

    int W = 0, H1 = -1, H2 = -1, I;

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> h[i];
        W += w[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (h[i] > H1)
        {
            H1 = h[i];
            I = i;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i != I)
        {
            H2 = max(h[i], H2);
        }
    }

//    cout << H1 << " " << H2 << endl;
//    cin.get();
//    cin.get();

    for (int i = 0; i < n; ++i)
    {
        if (i == I)
        {
            cout << (H2 * (W - w[i])) << " ";
        }
        else
        {
            cout << (H1 * (W - w[i])) << " ";
        }
    }


    //cin.get();
    //cin.get();


    return 0;

}