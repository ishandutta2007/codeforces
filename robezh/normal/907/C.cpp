#include <bits/stdc++.h>
using namespace std;

int n;
string s,k;
bool S[150];
char uni = '.';

void check_unique(){
    int cnt = 0;
    char k = '?';
    for(char c = 'a'; c <= 'z'; c++){
        if(S[c]) k = c, cnt++;
    }
    if(cnt == 1) uni = k;
    //cout << "now cnt = " << cnt << endl;

}

void add(string word){
    bool res[150];
    fill(res, res +150, false);
    for(int i = 0; i < word.size(); i++) res[word[i]] = true;
    for(char c = 'a' ; c <= 'z'; c++){
        S[c] &= res[c];
    }
    check_unique();
}

void elim(string word){
    bool res[150];
    for(int i = 0; i < word.size(); i++) res[word[i]] = true;
    for(char c = 'a' ; c <= 'z'; c++){
        S[c] &= !res[c];
    }
    check_unique();
}

void guess(string word){
    if(word[0] == uni) return;
    S[word[0]] = false;
    check_unique();
}

int main() {
    fill(S,S+150,true);

    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k >> s;
        if((k == "!" && uni != '.') || (k == "?" && uni != '.' && s[0] != uni)) cnt++;
        if(k == "!") add(s);
        else if(k == ".") elim(s);
        else guess(s);
    }
    cout << cnt;
}