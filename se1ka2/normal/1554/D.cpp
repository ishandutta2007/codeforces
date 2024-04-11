#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n / 2; i++) cout << 'a';
        cout << 'b';
        if(n > 1 && n % 2) cout << 'c';
        for(int i = 0; i < n / 2 - 1; i++) cout << 'a';
        cout << endl;
    }
}