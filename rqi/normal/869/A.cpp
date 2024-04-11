#include <bits/stdc++.h>

using namespace std;
int x[2002];
int y[2002];
set<int> t;
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        t.insert(x[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
        t.insert(y[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(t.find(x[i]^y[j])!=t.end()){
                ans++;
            }
        }
    }
    if(ans % 2 == 0){
        cout << "Karen";
    }
    else cout << "Koyomi";
}