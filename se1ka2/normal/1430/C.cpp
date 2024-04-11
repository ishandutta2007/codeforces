#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << 2 << endl;
        cout << n - 1 << " " << n << endl;
        for(int i = n - 2; i >= 1; i--){
            cout << i << " " << i + 2 << endl;
        }
    }
}