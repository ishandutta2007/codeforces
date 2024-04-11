#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

void do_operation(int x){
    reverse(a.begin(), a.begin() + x + 1);
    for(int i = 0; i <= x; ++i)
        a[i] = (1 - (a[i] - '0')) + '0';
}

void solve(){
    cin >> n;
    cin >> a >> b;

    vector<int> p;
    for(int i = n - 1; i >= 0; --i){
        if(b[i] == a[i])
            continue;
    
        if(a[0] != a[i]){
            do_operation(0);
            p.push_back(0);
        }

        do_operation(i);
        p.push_back(i);
    }

    cout << p.size() << " ";
    for(int x: p)
        cout << x + 1 << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}