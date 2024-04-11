#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int f,g,t;
    f=1;
    g=0;
    for (int i=2;i<=n;i++)
    {
        t=f;
        f=(2*t+g)% 1000000007;
        g=(3*t)% 1000000007;
    }
    cout << g;
    return 0;
}