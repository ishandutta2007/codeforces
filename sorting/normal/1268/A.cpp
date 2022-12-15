#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string a;
    cin >> a;

    bool increased = false;
    bool ok = true;
    for(int i = k; i < a.size(); ++i){
        if(a[i] > a[i - k] && !increased){
            ok = false;
            break;
        }

        if(a[i] < a[i - k])
            increased = true;
        a[i] = a[i - k];
    }

    if(!ok){
        for(int i = k - 1; i >= 0; --i){
            if(a[i] != '9'){
                a[i]++;
                break;
            }
            a[i] = '0';
        }
        for(int i = k; i < a.size(); ++i)
            a[i] = a[i - k];
    }

    cout << a.size() << "\n";
    cout << a << "\n";
}