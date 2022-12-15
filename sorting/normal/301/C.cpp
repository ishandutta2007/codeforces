#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << ("9\?\?>>\?\?0\n");
    for(int i = 0; i <= 8; ++i){
        char digit = (i + '0');
        cout << digit << "??" << ("<>") << (char)(digit + 1) << "\n";
    } 

    cout << "\?\?<>1\n";

    for(int i = 0; i <= 9; ++i){
        char digit = (i + '0');
        cout << "?" << digit << (">>") << digit << "?" << "\n";
    }

    cout << "?>>??\n";

    for(int i = 0; i <= 9; ++i){
        char digit = (i + '0');
        cout << digit << (">>?") << digit << "\n";
    }
}