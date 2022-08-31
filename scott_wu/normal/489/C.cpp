#include <iostream>
using namespace std;

int d[110];

int main()
{
    int M, S;
    cin >> M >> S;
    if (S > M * 9 || (M > 1 && S == 0))
    {
        cout << "-1 -1\n";
        return 0;
    }
    if (S == 0)
    {
        cout << "0 0\n";
        return 0;
    }
    
    d[0] = 1;
    int cm = S - 1;
    for (int i = M - 1; i >= 0; i--)
    {
        while (cm > 0 && d[i] < 9)
        {
            cm--;
            d[i]++;
        }
    }
    for (int i = 0; i < M; i++)
        cout << d[i];
    cout << " ";
    
    for (int i = 0; i < M; i++)
    {
        int k = 0;
        while (S && k < 9)
            k++, S--;
        cout << k;
    }
    cout << "\n";
}