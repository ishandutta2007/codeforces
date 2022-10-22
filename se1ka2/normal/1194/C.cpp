#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        string s, t, p;
        cin >> s >> t >> p;
        int n = s.size(), m = t.size(), l = p.size();
        s += '.';
        int j = 0;
        for(int i = 0; i < m; i++){
            if(s[j] == t[i]) j++;
        }
        if(j < n){
            cout << "NO" << endl;
            continue;
        }
        int a[26] {0}, b[26] {0};
        bool f = true;
        for(int i = 0; i < n; i++) a[s[i] - 'a']++;
        for(int i = 0; i < l; i++) a[p[i] - 'a']++;
        for(int i = 0; i < m; i++) b[t[i] - 'a']++;
        for(int i = 0; i < 26; i++) if(a[i] < b[i]){
            cout << "NO" << endl;
            f = false;
            break;
        }
        if(f) cout << "YES" << endl;
    }
}