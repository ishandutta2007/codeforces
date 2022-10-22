#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        map<int, int> mps, mpt;
        for(int i = 0; i < n; i++){
            mps[s[i] - 'a']++;
        }
        for(int i = 0; i < n; i++){
            mpt[t[i] - 'a']++;
        }
        bool f = true;
        for(int i = 0; i < 26; i++){
            if(mps[i] != mpt[i]){
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if(!f) continue;
        f = false;
        for(int i = 0; i < 26; i++){
            if(mps[i] >= 2){
                cout << "YES" << endl;
                f = true;
                break;
            }
        }
        if(f) continue;
        int ps[26];
        int pt[26];
        fill(ps, ps + 26, -1);
        fill(pt, pt + 26, -1);
        for(int i = 0; i < n; i++) ps[s[i] - 'a'] = i;
        for(int i = 0; i < n; i++) pt[t[i] - 'a'] = i;
        int eo = 0;
        for(int i = 0; i < 26; i++){
            int j;
            if(ps[i] != pt[i]){
                for(j = 0; j < 26; j++) if(pt[j] == ps[i]) break;
                swap(pt[i], pt[j]);
                eo++;
            }
        }
        if(eo % 2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}