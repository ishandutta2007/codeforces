#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n == 1 && k == 1){
        cout << 0 << endl;
        return 0;
    }
    if(k == 0){
        cout << s << endl;
        return 0;
    }
    if(s[0] != '1'){
        s[0] = '1';
        k--;
    }
    for(int i = 1; i < n; i++){
        if(k == 0) break;
        if(s[i] != '0'){
            s[i] = '0';
            k--;
        }
    }
    cout << s << endl;
}