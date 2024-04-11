#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if((a + b) % 2){
            cout << a * 2 + 2 << endl;
            for(int i = (a + b) / 2 - a; i <= (a + b) / 2 + a + 1; i++) cout << i << " ";
        }
        else{
            cout << a + 1 << endl;
            for(int i = (a + b) / 2 - a; i <= (a + b) / 2 + a; i += 2) cout << i << " ";
        }
        cout << endl;
    }
}