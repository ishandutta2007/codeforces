#include <iostream>

using namespace std;
const int MOD = 1000000007;

int val[2];

int main()
{
    int N;
    cin >> N;
    
    val[0] = val[1] = 0;
    for (int i = 0; i < N; i++)
    {
        val[i%2] = (val[i%2] + val[(i+1)%2] + 1) % MOD;
    }
    cout << (val[0] + val[1]) % MOD << "\n";
    //system ("Pause");
    return 0;
}