#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
int arr[MAXN];
int plo[MAXN][2];
int phi[MAXN][2];
int slo[MAXN][2];
int shi[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        if (c == '0')
            arr[i] = 0;
        else
            arr[i] = 1;
    } 

    plo[0][0] = plo[0][1] = 1e9;
    phi[0][0] = phi[0][1] = -1;
    slo[0][0] = slo[0][1] = 1e9;
    shi[0][0] = shi[0][1] = -1;
    for (int i = 0; i < N; i++)
    {
        int j = arr[i];
        plo[i+1][j] = min (plo[i][j], i);
        phi[i+1][j] = max (phi[i][j], i);
        plo[i+1][1-j] = plo[i][1-j];
        phi[i+1][1-j] = phi[i][1-j];
    }
    for (int i = 0; i < N; i++)
    {
        int j = arr[N-1-i];
        slo[i+1][j] = min (slo[i][j], N-1-i);
        shi[i+1][j] = max (shi[i][j], N-1-i);
        slo[i+1][1-j] = slo[i][1-j];
        shi[i+1][1-j] = shi[i][1-j];
    }

    if (phi[N][0] - plo[N][0] <= K - 1 ||
        phi[N][1] - plo[N][1] <= K - 1)
    {
        cout << "tokitsukaze\n";
        return 0;
    }

    for (int i = 0; i <= N - K; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int chi = max (phi[i][j], shi[N-K-i][j]);
            int clo = min (plo[i][j], slo[N-K-i][j]);
            if (chi - clo >= K)
            {
                cout << "once again\n";
                return 0;
            }
        }
    }
    cout << "quailty\n";
}