#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    while(true){
        if(n == 0 || m == 0) break;
        if(n >= m * 2) n %= m * 2;
        else if(m >= n * 2) m %= n * 2;
        else break;
    }
    cout << n << " " << m << endl;
}