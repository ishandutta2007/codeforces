#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int sum = 0, last = 0;
    for(int i = 0; i < n && k > 0; i++){
        if(s[i] - last >= 2){
            k--;
            sum += int(s[i] - 'a') + 1;
            last = int(s[i]);
        }
    }

    if(k > 0)cout << -1;
    else cout << sum;
}