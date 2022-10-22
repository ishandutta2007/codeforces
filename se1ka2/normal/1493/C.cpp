#include <iostream>
using namespace std;

bool judge(int mid, string s, int n, int k){
    int c[30]{0};
    for(int i = 0; i < mid; i++) c[s[i] - 'a']++;
    int d = n - mid;
    for(int i = 0; i < 26; i++){
        c[i] = (k - c[i] % k) % k;
        d -= c[i];
    }
    if(d < 0) return false;
    string t;
    for(int i = 0; i < d; i++) t += 'z';
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < c[i]; j++) t += char('a' + i);
    }
    if(t >= s.substr(mid)) return true;
    return false;
}

string ans(int l, string s, int n, int k){
    int c[30]{0};
    for(int i = 0; i < l; i++) c[s[i] - 'a']++;
    int d = n - l;
    for(int i = 0; i < 26; i++){
        c[i] = (k - c[i] % k) % k;
        d -= c[i];
    }
    string t = s.substr(0, l);
    if(l < n){
        if(d > 0 && c[s[l] - 'a' + 1] == 0){
            c[s[l] - 'a' + 1] = k;
            d -= k;
        }
        for(int j = s[l] - 'a' + 1; j < 26; j++){
            if(c[j]){
                t += char('a' + j);
                c[j]--;
                break;
            }
        }
    }
    for(int i = 0; i < d; i++) t += 'a';
    for(int j = 0; j < 26; j++){
        for(int i = 0; i < c[j]; i++) t += char('a' + j);
    }
    return t;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n % k){
            cout << -1 << endl;
            continue;
        }
        int left = 0, right = n + 1;
        while(right - left > 1){
            int mid = (right + left) / 2;
            if(judge(mid, s, n, k)) left = mid;
            else right = mid;
        }
        cout << ans(left, s, n, k) << endl;
    }
}