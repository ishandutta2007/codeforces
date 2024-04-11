#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int sum = a + b;
    for(int i = 0; i < n; i++){
        if(s[i] != '.') continue;
        if(i > 0 && s[i - 1] == 'a'){
            if(b == 0) continue;
            s[i] = 'b';
            b--;
        }
        else if(i > 0 && s[i - 1] == 'b'){
            if(a == 0) continue;
            s[i] = 'a';
            a--;
        }
        else{
            if(a + b == 0) continue;
            if(a < b){
                s[i] = 'b';
                b--;
            }
            else{
                s[i] = 'a';
                a--;
            }
        }
    }
    cout << sum - a - b << endl;
}