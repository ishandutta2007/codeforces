#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if ( n % 4 >=2)
    { cout << "-1\n"; return 0;}
    for (int i = 1; i <= n; i++)
    {
        if ( n % 4 == 1 && i == (n+1)/2) cout<<i<<" ";
        else if (i <= n / 2 && i % 2) cout << i + 1 << " ";
        else if ( i <= n/2) cout<< n-i+2 << " ";
        else if ((n - i) % 2) cout << n - i << " ";
          else cout<< i-1<<" ";
        }
        return 0;
    }
        //1 2 n n-1