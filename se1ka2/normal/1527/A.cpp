#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++){
            if((1 << i) > n){
                cout << (1 << (i - 1)) - 1 << endl;
                break;
            }
        }
    }
}