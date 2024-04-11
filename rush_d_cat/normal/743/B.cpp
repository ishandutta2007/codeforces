#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    int res = 1;
    while((k&1) == 0)
    {
        res++;
        k /= 2;
    }
    cout << res << endl;
}