#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> k >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++)cin >> s[i];

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < k; i++){
        int n1;
        cin >> n1;
        int m = 1000000010;
        vector<int> b(n1);
        for(int j = 0; j < n1; j++){
            cin >> b[j];
            b[j]--;
            m = min(m, a[b[j]]);
        }
        for(int j = 0; j < n1; j++)a[b[j]] = m;
    }

    map<string, int> b;
    for(int i = 0; i < n; i++)b[s[i]] = a[i];

    long long ans = 0;
    for(int i = 0; i < m; i++){
        string s1;
        cin >> s1;
        ans += b[s1];
    }

    cout << ans;
}