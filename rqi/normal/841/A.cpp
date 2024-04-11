#include <iostream>

using namespace std;
int letters[26];
int main() {
    int n, k;
    int ans = 0;
    string colors;
    cin >> n >> k >> colors;
    for(int i = 0; i < n; i++){
        letters[colors[i] - 'a'] ++;
    }
    for(int i = 0; i < 26; i++){
        if(letters[i] > k){
            ans = 1;
        }
    }
    if(ans == 0){
        cout << "YES";
    }
    else cout << "NO";
}