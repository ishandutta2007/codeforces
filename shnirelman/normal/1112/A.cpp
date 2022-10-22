#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];

    }

    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        s[i]--;
    }

    vector<int> mx(m, 0);
    for(int i = 0; i < n; i++){
        if(a[i] > mx[s[i]])mx[s[i]] = a[i];
    }

    int ans = 0;

    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        c--;
        if(mx[s[c]] != a[c])ans++;
    }

    cout << ans;
}