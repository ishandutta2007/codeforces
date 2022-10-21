#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e4 + 50;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int good[4];
int n;
string str;
int num[N];
string s[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};


int main() {
    cin >> n;
    cin >> str;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'G') num[i] = 0;
        else if(str[i] == 'H') num[i] = 1;
        else if(str[i] == 'R') num[i] = 2;
        else if(str[i] == 'S') num[i] = 3;
        else if(str[i] == '?') num[i] = -1;
    }
    int mn[4];
    int V[4], vcnt = 0;
    for(int ep = 0; ep < 1000; ep++) {
        fill(mn, mn + 4, 0);
        for(int i = 0; i < n; i++) {
            if(num[i] != -1) mn[num[i]]++;
            else {
                vcnt = 0;
                int mnv = 100000;
                for(int j = 0; j < 4; j++) mnv = min(mnv, mn[j]);
                for(int j = 0; j < 4; j++) if(mnv == mn[j]) V[vcnt++] = j;
                mn[V[rng() % vcnt]] ++;
            }
        }
        int mnv = 100000;
        for(int j = 0; j < 4; j++) mnv = min(mnv, mn[j]);
        for(int j = 0; j < 4; j++) if(mnv == mn[j]) good[j] = 1;
    }
    for(int i = 0; i < 4; i++) if(good[i]) cout << s[i] << endl;
}