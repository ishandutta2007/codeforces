#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    pair<int, int> shows[n];
    for(int i = 0; i < n; i++){
        cin >> shows[i].first >> shows[i].second;
    }
    int tv1 = -1, tv2 = -1;
    sort(shows, shows + n);
    for(int i = 0; i < n; i++){
        if(tv1 + 1 <= shows[i].first){
            tv1 = shows[i].second;
        }
        else if(tv2 + 1 <= shows[i].first){
            tv2 = shows[i].second;
        }
        else ans = -1;
    }
    if(ans == -1){
        cout << "NO";
    }
    else cout << "YES";
}