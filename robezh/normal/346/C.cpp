#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, M = (int)1e6 + 500, INF = (int)1e9;

int n;
int num[N], nxt[2 * M];
int a,b;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    scanf("%d%d", &a, &b);

    for(int i = 0; i < 2 * M; i++) nxt[i] = max(0, i-1);
    a -= b;
    sort(num, num+n);
    for(int i = 0; i < n; i++){
        if(i == 0 || num[i] != num[i-1]){
            for(int j = ((num[i] - 1 - b) % num[i] + num[i]) % num[i]; j <= a; j += num[i]){
                if(j - (num[i] - 1) >= 0) nxt[j] = min(nxt[j],  j - (num[i] - 1));
            }
            int nxt_a = a - (a + b) % num[i];
            if(nxt_a >= 0) nxt[a] = min(nxt[a], nxt_a);
        }
    }
    for(int j = 2 * M - 2; j >= 0; j--) nxt[j] = min(nxt[j], nxt[j+1]);

    int cnt = 0;
    for(int j = a; j != 0; j = nxt[j]) cnt++;
    cout << cnt << endl;
}