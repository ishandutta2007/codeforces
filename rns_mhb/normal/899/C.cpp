#include <iostream>
using namespace std;
long long int n;
int main()
{
    long long int  i, j;
    cin >> n;
    cout << n * (n + 1) / 2 % 2 << endl << n / 2 << ' ';
    for (i = n, j = 0; i > 1; i -= 2, j = !j) {
        cout<<i - j<<" ";
    }
    return 0;
}