#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int n = s.size();
        int d[4]{0};
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') d[0]++;
            if(s[i] == 'L') d[1]++;
            if(s[i] == 'U') d[2]++;
            if(s[i] == 'D') d[3]++;
        }
        if(min(d[0], d[1]) == 0){
            if(min(d[2], d[3]) == 0){
                cout << 0 << endl;
                cout << endl;
            }
            else{
                cout << 2 << endl;
                cout << "UD" << endl;
            }
        }
        else{
            if(min(d[2], d[3]) == 0){
                cout << 2 << endl;
                cout << "LR" << endl;
            }
            else{
                cout << (min(d[0], d[1]) + min(d[2], d[3])) * 2 << endl;
                for(int i = 0; i < min(d[0], d[1]); i++) cout << 'R';
                for(int i = 0; i < min(d[2], d[3]); i++) cout << 'U';
                for(int i = 0; i < min(d[0], d[1]); i++) cout << 'L';
                for(int i = 0; i < min(d[2], d[3]); i++) cout << 'D';
                cout << endl;
            }
        }
    }
}