#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;
    for(int i = 1; i < n; i++){
        if(str[i] != '?' && str[i] == str[i-1]) return !printf("NO");
    }
    for(int i = 0; i < n; i++){
        if(str[i] == '?'){
            if(i == 0 || i == n-1 || str[i-1] == '?' || str[i+1] == '?' || str[i-1] == str[i+1])
                return !printf("YES");
        }
    }
    return !printf("NO");
}