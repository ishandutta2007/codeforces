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
        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') c++;
        }
        if(c == 1) cout << "BOB" << endl;
        else if(c % 2) cout << "ALICE" << endl;
        else cout << "BOB" << endl;
    }
}