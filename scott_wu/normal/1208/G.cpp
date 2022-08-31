#include <bits/stdc++.h>
 
using namespace std;
int N, K;
int ncnt[1000100];
 
int main()
{
    cin >> N >> K; N++;
    for (int i = 1; i < N; i++)
    {
        ncnt[i] += i;
        for (int j = 2 * i; j < N; j += i)
            ncnt[j] -= ncnt[i];
    }

    sort (ncnt + 3, ncnt + N);
    long long nans = 0;
    for (int i = 0; i < K; i++)
        nans += ncnt[i+3];
    nans += min (K, 2);
    cout << nans << "\n";
    return 0;
}