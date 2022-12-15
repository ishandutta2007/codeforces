#include <bits/stdc++.h>

using namespace std;

void solve_test(){
    int n, k;
    cin >> n >> k;

    static const int k_N = 1e5 + 7;
    static int a[k_N];

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    bool is_k_in_a = false;
    for(int i = 0; i < n && !is_k_in_a; ++i)
        is_k_in_a = (a[i] == k);

    if(!is_k_in_a){
        cout << "no\n";
        return;
    }
    if(n == 1){
        cout << "yes\n";
        return;
    }

    for(int i = 0; i < n; ++i)
        a[i] = (a[i] >= k);

    bool answer = false;
    for(int i = 1; i < n && !answer; ++i){
        if(a[i] == 1 && a[i - 1] == 1)
            answer = true;
        if(i >= 2 && a[i] == 1 && a[i - 2] == 1)
            answer = true;
    }

    cout << (answer ? "yes" : "no") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve_test();
}