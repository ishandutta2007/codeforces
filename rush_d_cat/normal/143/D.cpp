#include <iostream>
using namespace std;
int n, m;

int main()
{
    cin >> n >> m;
    int ans = (m*n+1)/2;
    if(n > m) swap(n, m);
    if(n == 1) ans = m;
    if(n == 2) {
        if(m % 2 == 1) ans = m+1;
        if(m % 4 == 2) ans = m+2; 
    }
    cout << ans << endl;
}