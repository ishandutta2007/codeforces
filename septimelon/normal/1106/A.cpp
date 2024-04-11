#include <iostream>

using namespace std;

int main()
{
    char a[500][500];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int k = 0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
            if (a[i][j] == 'X' && a[i-1][j-1] == 'X' && a[i-1][j+1] == 'X' && a[i+1][j-1] == 'X' && a[i+1][j+1] == 'X')
                k++;
        }
    }
    cout << k << endl;
    return 0;
}