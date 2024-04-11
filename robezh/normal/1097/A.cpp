#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
string t[5];

int main(){
    cin >> s;
    for(int i = 0; i < 5; i++) cin >> t[i];

    for(int i = 0; i < 5; i++){
        if(t[i][0] == s[0]) return !printf("YES");
        if(t[i][1] == s[1]) return !printf("YES");
    }
    return !printf("NO");
}