#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int cnt[26];

int main(){
    cin >> n;
    cin >> str;
    fill(cnt, cnt+26, 0);
    for(char c : str) cnt[c-'a']++;
    for(int i = 0; i < 26; i++) if(cnt[i] >= 2) return !printf("Yes");
    printf(str.length() == 1 ? "Yes" : "No");
}