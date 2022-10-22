#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ca = 0, cb = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'A' && s[i + 1] == 'B') ca++;
        if(s[i] == 'B' && s[i + 1] == 'A') cb++;
    }
    if(ca == 0 && cb == 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'A' && s[i + 1] == 'B'){
            for(int j = i + 2; j < n - 1; j++){
                if(s[j] == 'B' && s[j + 1] == 'A'){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        if(s[i] == 'B' && s[i + 1] == 'A'){
            for(int j = i + 2; j < n - 1; j++){
                if(s[j] == 'A' && s[j + 1] == 'B'){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}