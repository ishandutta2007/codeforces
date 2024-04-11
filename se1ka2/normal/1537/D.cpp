#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2){
            cout << "Bob" << endl;
            continue;
        }
        int c = 0;
        while(n % 2 == 0){
            n /= 2;
            c++;
        }
        if(n == 1 && c % 2) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}