#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int n = s.size();
        sort(s.begin(), s.end());
        if(t != "abc" || s[0] != 'a') cout << s << endl;
        else{
            for(int i = 0; i < n; i++){
                if(s[i] == 'a' || s[i] == 'c') cout << s[i];
            }
            for(int i = 0; i < n; i++){
                if(s[i] != 'a' && s[i] != 'c') cout << s[i];
            }
            cout << endl;
        }
    }
}