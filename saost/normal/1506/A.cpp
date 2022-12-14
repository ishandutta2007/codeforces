#include <iostream>

using namespace std;
long long t,n,m,x;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        cout << (x+n-1)%n * m + (x+n-1)/n << '\n';
    }
}