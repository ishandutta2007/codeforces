#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int d[30]{0};
        int k = 0;
        for(int i = 0; i < n; i++){
            if(!d[s[i] - 'a']) k++;
            d[s[i] - 'a']++;
        }
        bool b[30]{0};
        vector<char> v;
        for(int i = n - 1; i >= 0; i--){
            if(!b[s[i] - 'a']){
                b[s[i] - 'a'] = true;
                v.push_back(s[i]);
                d[s[i] - 'a'] /= k;
                k--;
            }
        }
        int c = 0;
        for(int i = 0; i < 26; i++) c += d[i];
        string u = s.substr(0, c);
        string ans = u;
        string w;
        k = v.size();
        while(k--){
            w += u;
            string x;
            for(int i = 0; i < (int)u.size(); i++){
                if(u[i] != v[k]) x += u[i];
            }
            swap(u, x);
        }
        if(w != s){
            cout << -1 << endl;
            continue;
        }
        cout << ans << " ";
        for(int i = (int)v.size() - 1; i >= 0; i--) cout << v[i];
        cout << endl;
    }
}