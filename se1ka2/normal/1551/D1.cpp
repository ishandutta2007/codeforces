#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        if(m % 2){
            m--;
        }
        if(n % 2){
            k -= m / 2;
            n--;
        }
        if(k < 0 || k > n * m / 2 || k % 2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}