#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

map<string, int> mp1;
map<string, int> mpPos;

string str[10100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        map<string, int> mp2;
        for (int i = 0; i < s.size(); i++){
            string cur;
            for (int j = i; j < s.size(); j++){
                cur += s[j];
                mp2[cur] = 1;
            }
        }
        for (auto it = mp2.begin(); it != mp2.end(); it++){
            ++mp1[it->first];
            if (mpPos.find(it->first) == mpPos.end())
                mpPos[it->first] = i;
        }
        str[i] = s;
    }
    int tt;
    cin >> tt;
    while(tt--){
        string s;
        cin >> s;
        if (mp1.find(s) == mp1.end()){
            cout << "0 -\n";
        }
        else {
            cout << mp1[s] << ' ' << str[mpPos[s]] << "\n";
        }
    }

}

/**

*/