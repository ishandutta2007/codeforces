#include <iostream>

using namespace std;

int cool(long long n)
{
    cout << n << " ";
    long long p=-1, i;
    for (i=n;i>=2;i--)
      if (n%i==0) p = n / i;
    if (p > -1) cool(p);
    return 0;
}

int main()
{
    long long n;
    cin >> n;
    cool(n);
    return 0;
}