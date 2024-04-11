#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[2];

int main(){
    cin >> n;
    cin >> s;
    for(char c : s) cnt[c-'0']++;
    if(cnt[1] == 0) cout << s;
    else{
        cout << "1";
        while(cnt[0]--) cout << "0";
    }
}