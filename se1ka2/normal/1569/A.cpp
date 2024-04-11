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
        bool f = false;
        for(int i = 0; i < n - 1; i++){
            if(s[i] != s[i + 1]){
                cout << i + 1 << " " << i + 2 << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << -1 << " " << -1 << endl;
    }
}