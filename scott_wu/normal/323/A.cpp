#include <iostream>

using namespace std;

int main()
{
    int K; cin >> K;
    if (K % 2)
    {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < K; k++)
            {
                cout << ((i + j/2 + k/2) % 2 ? 'b' : 'w');
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}