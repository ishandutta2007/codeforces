#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    bool b[55];
    bool nb[55];
    
    for (int i = 0; i < N; i++)
    {
        char ch; cin >> ch;
        b[i] = (ch == 'B');
    }
    
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < N; j++)
            nb[j] = b[j];
        for (int j = 0; j < N - 1; j++)
            if (b[j] && !b[j+1])
                swap (nb[j], nb[j+1]);
        for (int j = 0; j < N; j++)
            b[j] = nb[j];
    }
    
    for (int i = 0; i < N; i++)
        cout << ((b[i]) ? 'B' : 'G');
    cout << "\n";
    return 0;
}