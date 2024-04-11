#include <bits/stdc++.h>
using namespace std;

const int MAXL = (int)2e5 + 500;

int T, n;
int d[MAXL], res[MAXL];
int odd[10], ocnt = 0;
bool eq = true;
string s;

bool lotsofzero(string s){
    if(s[0] != '1' || (s[s.length()-1] != '0' && s[s.length()-1] != '1')) return false;
    for(int i = 1; i < s.length()-1; i++) if(s[i] != '0') return false;
    return true;
}

bool dfs(int t){
    if(t == -1) return !eq;
    if(ocnt > t+1) return false;
    for(int k = (eq ? d[t] : 9); k >= 0; k--){
        if(ocnt == t+1 && !odd[k]) continue;

        bool change = false;
        if(k != d[t] && eq) eq = false, change = true;

        ocnt += (odd[k] ? -1 : 1), odd[k] = !odd[k];
        bool next = dfs(t-1);
        odd[k] = !odd[k], ocnt += (odd[k] ? 1 : -1);
        if(change) eq = true;

        if(next){
            res[t] = k;
            return true;
        }
    }
    return false;

}

int main(){
    fill(odd, odd+10, 0);
    cin >> T;
    getchar();
    while(T--){
        getline(cin, s);
        if(lotsofzero(s)){
            for(int i = 0; i < s.length()-2; i++) printf("9");
            printf("\n");
        }
        else{
            for(int i = 0; i < s.length(); i++) d[i] = (s[s.length()-1-i] - '0');
            n = s.length();
            dfs(n-1);
            for(int i = n-1; i >= 0; i--) printf("%d", res[i]);
            printf("\n");
        }
    }
}