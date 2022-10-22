#include <iostream>
#include <string>
using namespace std;

char t[200005];

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n + 2; i++){
            if(i % 3 == 0) t[i] = 'R';
            if(i % 3 == 1) t[i] = 'G';
            if(i % 3 == 2) t[i] = 'B';
        }
        int ans = 1000000;
        for(int i = 0; i < 3; i++){
            int now = 0;
            for(int j = 0; j < k; j++){
                if(s[j] != t[j + i]) now++;
            }
            ans = min(now, ans);
            for(int j = k; j < n; j++){
                if(s[j] != t[j + i]) now++;
                if(s[j - k] != t[j - k + i]) now--;
                ans = min(ans, now);
            }
        }
        cout << ans << endl;
    }
}