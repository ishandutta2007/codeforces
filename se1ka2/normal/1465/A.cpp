#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int l = n;
        for(; l > 0; l--){
            if(s[l - 1] != ')') break;
        }
        if(l * 2 >= n) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}