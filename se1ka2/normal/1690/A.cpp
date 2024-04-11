#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[3] = {2, 1, 0};
        for (int i = 0; i < n - 3; i++)
        {
            a[i % 3]++;
        }
        cout << a[1] << " " << a[0] << " " << a[2] << endl;
    }
}