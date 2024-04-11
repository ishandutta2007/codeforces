#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        bool g = false;
        for(int i = 0; i < n; i++){
            for(int r = i; r < n; r++){
                int j = i, k = 0;
                bool f = true;
                bool right = true;
                while(k < m){
                    if(k == m) break;
                    if(j < 0 || s[j] != t[k]){
                        f = false;
                        break;
                    }
                    if(j == r) right = false;
                    if(right) j++;
                    else j--;
                    k++;
                }
                if(f) g = true;
            }
        }
        if(g) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}