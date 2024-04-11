#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        bool f = false;
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int sa[26] {0};
        int ta[26] {0};
        for(int i = 0; i < n; i++){
            sa[s[i] - 'a']++;
            ta[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(sa[i] > 0 && ta[i] > 0){
                cout << "YES" << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << "NO" << endl;
    }
}