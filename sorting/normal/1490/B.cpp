#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int c[3];
        fill(c, c + 3, 0);
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            c[a % 3]++;
        }

        int ans = 0;
        while(c[0] != c[1] || c[0] != c[2]){
            bool ok = false;
            for(int i = 0; i < 3; ++i){
                int &curr = c[i], &nxt = c[(i + 1) % 3];
                if(curr != n / 3 && nxt != n / 3){
                    if(curr > n / 3 && nxt < n / 3){
                        curr--;
                        nxt++;
                        ok = true;
                        break;
                    }
                }
            }
            if(!ok){
                for(int i = 0; i < 3; ++i){
                    int &curr = c[i], &nxt = c[(i + 1) % 3];
                    if(curr >= n / 3 && nxt < n / 3){
                        curr--;
                        nxt++;
                        break;
                    }
                }
            }
            ans++;
        }

        cout << ans << "\n";
    }
}