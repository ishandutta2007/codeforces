#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main(){
    cin >> n;
    getchar();
    getline(cin, str);

    //cout << str;
    int time = 105;
    while(time--){
        if(str.length() < 2) break;
        for(int i = 0; i < str.length()-1; i++){
            //cout << str.substr(i,i+2) << endl;
            if(str.substr(i,2) == "UR" || str.substr(i,2) == "RU"){
                string s = "";
                if(i > 0){
                    s += str.substr(0,i);
                }
                s += "D";
                if(i+2 != str.length()) s += str.substr(i+2,(int)(str.length())-(i+2));
                str = s;
                //cout << str << endl;
                break;
            }
        }
    }
    cout << str.length();

}