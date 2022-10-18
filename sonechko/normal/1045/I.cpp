#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int SZ = 67108864;

map<int, int> mpKol0, mpKol1;

int n;

ll ans = 0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int num = 0;
        for (int j = 0; j < s.size(); j++){
            int cur = s[j]-'a';
            num ^= (1<<cur);
        }
        if (s.size() % 2 == 0){
            ans += mpKol0[num];
            for (int c = 0; c < 26; c++){
                num ^= (1<<c);
                ans += mpKol1[num];
                num ^= (1<<c);
            }
            ++mpKol0[num];
        } else {
            ans += mpKol1[num];
            for (int c = 0; c < 26; c++){
                num ^= (1<<c);
                ans += mpKol0[num];
                num ^= (1<<c);
            }
            ++mpKol1[num];
        }
    }
    cout << ans;


}