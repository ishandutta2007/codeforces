#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,m;
int cnt[N];
int tot = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--){
        int a;
        cin >> a; a--;
        if(cnt[a] == 0) tot++;
        cnt[a] ++;
        if(tot == n){
            cout << 1;
            for(int i = 0; i < n; i++){
                cnt[i]--;
                if(cnt[i] == 0) tot--;
            }
        }
        else cout << 0;
    }
}