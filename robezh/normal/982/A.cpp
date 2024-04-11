#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    if(n == 1) return !printf(s[0] == '1' ? "Yes" : "No");

    for(int i = 0; i < n-1; i++){if(s[i] == '1' && s[i+1] == s[i]) return !printf("No");}
    int cnt0 = 0;
    int fir = 0, las = n-1;
    while(fir < n && s[fir] == '0') fir++;
    if(fir >= 2) return !printf("No");
    while(las >= 0 && s[las] == '0') las--;
    if(las <= n-1 - 2) return !printf("No");
    for(int i = fir; i <= las; i++){
        if(s[i] == '0') cnt0 ++;
        else cnt0 = 0;
        if(cnt0 >= 3) return !printf("No");
    }
    return !printf("Yes");

}