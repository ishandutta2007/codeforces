#include <iostream>

#define LL long long

LL gcd (LL a, LL b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}



using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        LL n;
        cin >> n;
        LL g = gcd(4*n,n+1);
        cout << ((4*n)/g)+1 << endl;
    }
    return 0;
}