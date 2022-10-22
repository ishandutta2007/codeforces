#include <iostream>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    set<int> st[26];
    for(int i = 0; i < n; i++){
        st[s[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
/*        for(int i = 0; i < 26; i++){
            for(auto itr = st[i].begin(); itr != st[i].end(); itr++) cout << *itr << " ";
            cout << endl;
        }*/
        int w;
        cin >> w;
        if(w == 1){
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            st[s[pos] - 'a'].erase(pos);
            st[c - 'a'].insert(pos);
            s[pos] = c;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            for(int i = 0; i < 26; i++){
                if(st[i].lower_bound(l) != st[i].end() && *st[i].lower_bound(l) <= r) ans++;
            }
            cout << ans << endl;
        }
    }
}