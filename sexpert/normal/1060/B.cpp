#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, np;
    cin >> n;
    np = n + 1ll;
    int sum = 0;
    int d = 0;
    while(n > 0)
    {
        sum += (n % 10);
        n /= 10;
        d++;
    }
    while(np%10 == 0)
    {
        d--;
        np /= 10;
    }
    if(np == 1)
        d++;
    cout << sum + 9*(d - 1) << endl;
}