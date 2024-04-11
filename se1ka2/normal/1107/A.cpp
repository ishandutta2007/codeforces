#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n >= 3){
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " " << s.substr(1) << endl;;
        }
        if(n == 2){
            if(s[1] > s[0]){
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << s[0] << " " << s[1] << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}