#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int q;
string a, b;

int main(){
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(b == "a")
            puts("1");
        else if(b.find('a') != string::npos)
            puts("-1");
        else
            cout << (1ll << a.length()) << endl;
    }
    return 0;
}