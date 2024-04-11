#include<bits/stdc++.h>
using namespace std;

main(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') {
            cout << 1 << " "<< a%4 + 1 << endl;
            a++;
        }
        else{
            cout << 4  <<" "<< (b % 2)*2+1 << endl;
            b++;
        }
    }
}