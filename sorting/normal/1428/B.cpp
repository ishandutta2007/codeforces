#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n; string s;
        cin >> n >> s;

        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '<') cnt1++;
            if(s[i] == '>') cnt2++;
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            char prev = s[i];
            char nxt = s[(i + 1) % n];
            if(prev == '-' || nxt == '-') cnt++;
            else if(prev == nxt){
                if(prev == '<') cnt += !cnt2;
                if(prev == '>') cnt += !cnt1;
            }
        }

        cout << cnt << "\n";
    }
}