#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        if(n % 2){
            cout << 7;
            for(int i = 0; i < (n - 2) / 2; i++) cout << 1;
        }
        else{
            for(int i = 0; i < n / 2; i++) cout << 1;
        }
        cout << endl;
    }
}