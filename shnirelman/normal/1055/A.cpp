#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
    int n, s;
    cin >> n >> s;

    vector<int> a(n), b(n);
    for(int i =  0; i < n; i++){
        cin >> a[i];
    }
    for(int i =  0; i < n; i++){
        cin >> b[i];
    }

    if(a[0] == 0){
        cout << "NO";
        return 0;
    }
    if(a[s - 1] == 1){
        cout << "YES";
        return 0;
    }
    if(b[s - 1] == 0){
        cout << "NO";
        return 0;
    }
    for(int i = s - 1; i < n; i++){
        if(a[i] == 1 && b[i] == 1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}