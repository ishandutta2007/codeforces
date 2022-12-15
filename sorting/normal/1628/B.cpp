#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> s(n);
        for(int i = 0; i < n; ++i)
            cin >> s[i];

        bool yes = false;
        for(int i = 0; i < n; ++i){
            string t = s[i];
            reverse(all(t));
            if(t == s[i]){
                yes = true;
                break;
            }
        }

        if(yes){
            cout << "YES\n";
            continue;
        }

        set<string> st2, st3, st4;
        for(int i = 0; i < n; ++i){
            if(s[i].size() == 2) st2.insert(string(1, s[i][0]) + string(1, s[i][1]));
            else{
                st3.insert(string(1, s[i][0]) + string(1, s[i][1]));
                st4.insert(s[i]);
            }

            if(s[i].size() == 2){
                if(st3.count(string(1, s[i][s[i].size() - 1]) + string(1, s[i][s[i].size() - 2]))){
                    yes = true;
                    break;
                }
                if(st2.count(string(1, s[i][s[i].size() - 1]) + string(1, s[i][s[i].size() - 2]))){
                    yes = true;
                    break;
                }
            }
            else{
                if(st2.count(string(1, s[i][s[i].size() - 1]) + string(1, s[i][s[i].size() - 2]))){
                    yes = true;
                    break;
                }
                if(st4.count(string(1, s[i][2]) + string(1, s[i][1]) + string(1, s[i][0]))){
                    yes = true;
                    break;
                }
            }
        }
            

        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}