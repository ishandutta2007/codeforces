#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = s;
    int o = 0, z = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0') z++;
        if(s[i] == '1') o++;
        if(s[i] == '1' && (s[i - 1] == '0' || i == 0)){
            int j = i;
            int c;
            for(c = 0; c < o - z; c++){
                if(t[j + c] == '0') break;
                t[j + c] = '0';
            }
            z += c;
        }
    }
    cout << t << endl;
}