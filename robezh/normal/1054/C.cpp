#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
typedef pair<int, int> P;

int n;
int l[N], r[N];
P tot[N];
int res[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++){
        cin >> r[i];
        tot[i].first = l[i] + r[i];
        tot[i].second = i;
    }
    sort(tot, tot + n);
    for(int i = 0; i < n; ){
        int r = i;
        while(r < n && tot[r].first == tot[i].first) r++;
        if(tot[i].first != i) return !printf("NO");
        for(int j = i; j < r; j++){
            res[tot[j].second] = n - i;
        }
        i = r;
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i + 1; j < n; j++) if(res[j] > res[i]) cnt++;
        if(cnt != r[i]) return !printf("NO");
        cnt = 0;
        for(int j = 0; j < i; j++) if(res[j] > res[i]) cnt++;
        if(cnt != l[i]) return !printf("NO");
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}