#include <bits/stdc++.h>

using namespace std;

int n, m;
string S[1007];
string word;
bool revel[300];
int cnt[300];

bool equ(string a, string b) {
    for(int i = 0 ; i < n ; i++) {
        if(a[i] != '*' && a[i] != b[i])
            return false;
        if(a[i] == '*' && revel[b[i]])
            return false;
    }
    return true;
}

bool is_in(char c, string s) {
    for(char d : s)
        if(d == c)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin >> word;
    cin >> m;
    for(int i = 0 ; i < m ; i++)
        cin >> S[i];

    for(char c : word)
        revel[c] = true;

    int cnt2 = 0;
    for(int i = 0; i < m ; i++) {
        if(!equ(word, S[i]))
            continue;
        cnt2++;

        for(char let = 'a' ; let <= 'z' ; let++)
            if(is_in(let, S[i]))
                cnt[let]++;
    }

    int res = 0;
    for(char let = 'a' ; let <= 'z' ; let++)
        if(cnt[let] == cnt2 && !revel[let])
            res++;

    cout << res;

    return 0;
}