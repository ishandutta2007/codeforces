#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int d[26]{0};
        for(int i = 0; i < n; i++) d[s[i] - 'a']++;
        for(int i = 0; i < n; i++){
            d[s[i] - 'a']--;
            if(d[s[i] - 'a'] == 0){
                cout << s.substr(i) << endl;
                break;
            }
        }
    }
}