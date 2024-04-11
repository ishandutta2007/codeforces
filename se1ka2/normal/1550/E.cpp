#include <iostream>
using namespace std;

int d[20][200005];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int left = 0, right = n + 1;
    while(right - left > 1){
        for(int j = 0; j < k; j++){
            for(int i = 0; i <= n + 1; i++) d[j][i] = n + 1;
        }
        int mid = (right + left) / 2;
        for(int j = 0; j < k; j++){
            int c = 0;
            int last = 0;
            for(int i = 1; i <= n; i++){
                if(s[i - 1] == char('a' + j) || s[i - 1] == '?') c++;
                else c = 0;
                if(c >= mid){
                    for(; last <= i - mid; last++) d[j][last] = i;
                }
            }
        }
        int e[200005];
        e[0] = 0;
        for(int b = 1; b < (1 << k); b++) e[b] = n + 1;
        for(int b = 1; b < (1 << k); b++){
            for(int j = 0; j < k; j++){
                if(!((b >> j) & 1)) continue;
                e[b] = min(e[b], d[j][e[b ^ (1 << j)]]);
            }
        }
        if(e[(1 << k) - 1] <= n) left = mid;
        else right = mid;
    }
    cout << left << endl;
}