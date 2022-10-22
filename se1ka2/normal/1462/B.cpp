#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string t;
        cin >> n >> t;
        if(n < 4){
            cout << "NO" << endl;
            continue;
        }
        bool f = false;
        for(int i = 0; i <= 4; i++){
            if(t.substr(0, i) + t.substr(n - (4 - i)) == "2020") f = true;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}