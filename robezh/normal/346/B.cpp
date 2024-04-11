#include <bits/stdc++.h>
using namespace std;

string s1, s2, vir;
int nxt[105][30];
string dp[105][105][105];

int ch(char a){return a - 'A';}

string maxs(string a, string b){
    return a.length() > b.length() ? a : b;
}

string subs(string s, int a, int b){
    return s.substr(a, b-a);
}

int main(){
    cin >> s1 >> s2 >> vir;

    for(int i = 0; i <= vir.length(); i++){
        for(char c = 'A'; c <= 'Z'; c++){
            string s = vir.substr(0, i) + c;
            while(vir.substr(0, s.length()) != s){
                s = s.substr(1);
            }
            nxt[i][ch(c)] = s.length();
        }
    }
    for(int i = 0; i < s1.length(); i++){
        for(int j = 0; j < s2.length(); j++){
            if(s1[i] == s2[j]){
                for(int k = 0; k < vir.length(); k++){
                    dp[i+1][j+1][nxt[k][ch(s1[i])]] =
                            maxs(dp[i+1][j+1][nxt[k][ch(s1[i])]],
                            dp[i][j][k] + s1[i]);
                }
            }
            for(int k = 0; k < vir.length(); k++){
                dp[i+1][j+1][k] = maxs(dp[i+1][j][k], dp[i+1][j+1][k]);
                dp[i+1][j+1][k] = maxs(dp[i][j+1][k], dp[i+1][j+1][k]);
            }
        }
    }
    string res;
    for(int i = 0; i < vir.length(); i++) res = maxs(res, dp[s1.length()][s2.length()][i]);
    cout << (res == "" ? "0" : res);
}