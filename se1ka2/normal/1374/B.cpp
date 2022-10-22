#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int r = 0, l = 0;
        while(n % 2 == 0){
            n /= 2;
            r++;
        }
        while(n % 3 == 0){
            n /= 3;
            l++;
        }
        if(n != 1){
            cout << -1 << endl;
        }
        else if(r > l){
            cout << -1 << endl;
        }
        else{
            cout << l - r + l << endl;
        }
    }
}