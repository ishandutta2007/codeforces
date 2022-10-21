#include <bits/stdc++.h>
using namespace std;

string str;
int scnt[5005][26][26];
int uninum[5005][26];
int scntsum[5005][26];
int acnt[26];

int ch(char c){return c-'a';}

int main(){
    getline(cin, str);
    int len = str.length();
    for(int i = 0; i < str.length(); i++) acnt[ch(str[i])]++;
    for(int i = 0; i < str.length(); i++){
        for(int step = 1; step < str.length(); step++){
            scnt[step][ch(str[i])][ch(str[(i+step)%len])]++;
            scntsum[step][ch(str[i])] ++;
        }
    }
    for(int step = 1; step < str.length(); step++){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(scnt[step][i][j] == 1) uninum[step][i]++;
            }
        }
    }

    double res = 0;
    for(int c = 0; c < 26; c++){
        double lmin = 0;
        for(int step = 1; step < str.length(); step++){
            lmin = max(lmin, (double)uninum[step][c] / scntsum[step][c]);
        }
        res += lmin * (double)acnt[c] / (double)(str.length());
    }
    //cout << uninum[3][ch('i')];
    cout << fixed << setprecision(10) << res << endl;
}