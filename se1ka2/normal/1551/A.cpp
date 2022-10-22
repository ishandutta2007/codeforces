#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 3 == 0) cout << n / 3 << " " << n / 3 << endl;
        if(n % 3 == 1) cout << n / 3 + 1 << " " << n / 3 << endl;
        if(n % 3 == 2) cout << n / 3 << " " << n / 3 + 1 << endl;
    }
}