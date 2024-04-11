#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        int b[3]{0};
        for(int i = 0; i < n; i++){
            if(s[i] < 'A') b[0]++;
            else if(s[i] < 'a') b[1]++;
            else b[2]++;
        }
        if(b[0] == n){
            s[0] = 'A';
            s[1] = 'a';
        }
        else if(b[1] == n){
            s[0] = '0';
            s[1] = 'a';
        }
        else if(b[2] == n){
            s[0] = '0';
            s[1] = 'A';
        }
        else if(b[0] == 0){
            if(b[1] != 1){
                for(int i = 0; i < n; i++){
                    if(s[i] < 'a'){
                        s[i] = '0';
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < n; i++){
                    if(s[i] >= 'a'){
                        s[i] = '0';
                        break;
                    }
                }
            }
        }
        else if(b[1] == 0){
            if(b[0] != 1){
                for(int i = 0; i < n; i++){
                    if(s[i] < 'A'){
                        s[i] = 'A';
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < n; i++){
                    if(s[i] >= 'a'){
                        s[i] = 'A';
                        break;
                    }
                }
            }
        }
        else if(b[2] == 0){
            if(b[0] != 1){
                for(int i = 0; i < n; i++){
                    if(s[i] < 'A'){
                        s[i] = 'a';
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < n; i++){
                    if(s[i] >= 'A'){
                        s[i] = 'a';
                        break;
                    }
                }
            }
        }
        cout << s << endl;
    }
}