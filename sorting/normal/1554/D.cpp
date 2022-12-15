#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n % 2 == 0){
            for(int i = 0; i < n / 2; ++i)
                cout << 'a';
            cout << 'b';
            for(int i = 0; i < n / 2 - 1; ++i)
                cout << 'a';
            cout << "\n";
        }
        else{
            if(n == 1){
                cout << "a\n";
                continue;
            }
            for(int i = 0; i < n / 2; ++i)
                cout << 'a';
            cout << "bc";
            for(int i = 0; i < n / 2 - 1; ++i)
                cout << 'a';
            cout << "\n";
        }
    }
}