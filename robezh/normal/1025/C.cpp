#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main(){
    cin >> str;
    n = str.length();
    str += str;
    int res = 0, cnt = 0;
    //cout << str << endl;
    for(int i = 0; i < str.length(); i++){
        if(i == str.length()-1 || str[i] == str[i+1]){
            res = max(res, cnt + 1);
            cnt = 0;
        }
        else cnt++;
    }
    cout << min(res, n) << endl;

}