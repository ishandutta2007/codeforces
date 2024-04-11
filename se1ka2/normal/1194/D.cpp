#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, k;
        cin >> n >> k;
        if(k % 3 == 0){
            n %= (k + 1);
            if(n % 3 == 0 && n != k) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
        else{
            if(n % 3 == 0) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }
}