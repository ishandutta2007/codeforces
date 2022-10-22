#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000;

ll a[200005];
ll rest[200005][42];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            rest[i][0] = INF;
            for(int c = 1; c <= 40; c++) rest[i][c] = -1;
        }
        int ans = 1;
        for(int c = 1; c <= 40; c++){
            int l = n - 1;
            for(int i = n - 1; i >= 0; i--){
                if(rest[i][c - 1] == -1) continue;
                for(l = min(l, i - 1); l >= 0; l--){
                    if(a[i] - a[l] <= rest[i][c - 1] - (a[i] - a[l])){
                        rest[l][c] = max(rest[l][c], a[i] - a[l]);
                        ans = c + 1;
                    }
                    else break;
                }
            }
            int r = 0;
            for(int i = 0; i < n; i++){
                if(rest[i][c - 1] == -1) continue;
                for(; r < i; r++){
                    if(a[i] - a[r] >= rest[i][c - 1] - (a[i] - a[r])){
                        if(a[i] - a[r] <= rest[i][c - 1]){
                            rest[r][c] = max(rest[r][c], rest[i][c - 1] - (a[i] - a[r]));
                            ans = c + 1;
                        }
                        if(i + 1 < n && rest[i + 1][c - 1] != -1 &&
                           a[i + 1] - a[r] >= rest[i + 1][c - 1] - (a[i + 1] - a[r]) &&
                           a[i + 1] - a[r] <= rest[i + 1][c - 1] &&
                           rest[i + 1][c - 1] - (a[i + 1] - a[r]) > rest[r][c]) break;
                    }
                    else break;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(rest[i][40] == 0){
                int j;
                for(j = i - 1; j >= 0; j--){
                    if(rest[j][40] == 0) ans = max(ans, 41 + i - j);
                    else{
                        i = j;
                        break;
                    }
                }
                i = j;
            }
        }
        cout << n - ans << endl;
    }
}