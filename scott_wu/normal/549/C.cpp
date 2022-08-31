#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int N, K;
int O, E;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    
    O = E = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x % 2 == 1)
            O++;
        else
            E++;
    }
    
    if (K == N)
    {
        if (O % 2 == 0)
            cout << "Daenerys\n";
        else
            cout << "Stannis\n";
        return 0;
    }
    
    if ((N - K) % 2 == 0)
    {
        if (E <= (N - K) / 2 && (K % 2 == 1))
            cout << "Stannis\n";
        else
            cout << "Daenerys\n";
    }
    else
    {
        if (O <= (N - K) / 2)
        {
            cout << "Daenerys\n";
        }
        else if (E <= (N - K) / 2 && (K % 2 == 0))
        {
            cout << "Daenerys\n";
        }
        else if (O == (N - K) / 2 + 1 && E == (N - K) / 2 + 1 && (K % 2 == 0))
        {
            cout << "Daenerys\n";
        }
        else
            cout << "Stannis\n";
    }
    
    return 0;
}