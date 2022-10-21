#include <bits/stdc++.h>
using namespace std;

int n;
string s[2];

int main(){
    getline(cin, s[0]);
    getline(cin, s[1]);



    n = s[0].length();
    int res = 0;
    while(true){
        bool good = false;
        for(int i = 0; i < n; i++){
            if(s[0][i] == s[1][i] && s[0][i]== '0'){
                if(i >= 1 && s[0][i-1] == '0'){
                    s[0][i] = s[1][i] = s[0][i-1] = 'X';
                    good = true;
                    break;
                }else if(i >= 1 && s[1][i-1] == '0'){
                    s[0][i] = s[1][i] = s[1][i-1] = 'X';
                    good = true;
                    break;
                }else if(i < n-1 && s[0][i+1] == '0'){
                    s[0][i] = s[1][i] = s[0][i+1] = 'X';
                    good = true;
                    break;
                }else if(i < n-1 && s[1][i+1] == '0'){
                    s[0][i] = s[1][i] = s[1][i+1] = 'X';
                    good = true;
                    break;
                }
            }

        }
        //cout << res;
        if(good){res ++;}
        else break;


    }
    cout << res;
}