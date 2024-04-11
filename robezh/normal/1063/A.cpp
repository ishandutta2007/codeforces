#include <bits/stdc++.h>
using namespace std;

const int N = 250;

int n;
string str;
int cnt[N];

int main(){
    int n;
    cin >> n;
    cin >> str;
    for(char c : str) cnt[c] ++;
    for(char c = 'a'; c <= 'z'; c++){
        for(int i = 0; i < cnt[c]; i++) cout << c;
    }
}