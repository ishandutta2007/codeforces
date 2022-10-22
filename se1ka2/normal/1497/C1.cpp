#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n % 2){
            cout << n / 2 << " " << n / 2 << " " << 1 << endl;
        }
        else if(n % 4){
            cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << endl;
        }
        else{
            cout << n / 4 << " " << n / 4 << " " << n / 2 << endl;
        }
    }
}