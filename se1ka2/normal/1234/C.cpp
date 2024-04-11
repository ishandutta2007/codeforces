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
        string s[2];
        cin >> s[0] >> s[1];
        int i = 0, j = 0;
        bool t = false;
        while(true){
            if(t){
                if(s[i][j] == '1' || s[i][j] == '2'){
                    cout << "NO" << endl;
                    break;
                }
                else{
                    if(j == n - 1){
                        if(i == 1) cout << "YES" << endl;
                        else cout << "NO" << endl;
                        break;
                    }
                    j++;
                    t = false;
                }
            }
            else{
                if(s[i][j] == '1' || s[i][j] == '2'){
                    if(j == n - 1){
                        if(i == 1) cout << "YES" << endl;
                        else cout << "NO" << endl;
                        break;
                    }
                    j++;
                }
                else{
                    i = 1 - i;
                    t = true;
                }
            }
        }
    }
}