#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int f = 0; f < t; f++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                l = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                r = i;
                break;
            }
        }
        if(l == -1) cout << n << endl;
        else cout << max((n - l) * 2, (r + 1) * 2) << endl;
    }
}