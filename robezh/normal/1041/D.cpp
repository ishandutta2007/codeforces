#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n, h;
int l[N], r[N];

int main(){
    scanf("%d%d", &n, &h);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &l[i], &r[i]);
    }
    int res = 0;

    int ri = 0, rem = h;
    int tot = r[0] - l[0];
    while(ri < n-1 && rem > l[ri+1] - r[ri]){
        rem -= l[ri+1] - r[ri];
        ri++;
        tot += r[ri] - r[ri-1];
    }
    res = max(tot + rem, res);
    //cout << ri << ": " <<tot << "," << rem << endl;
    for(int i = 1; i < n; i++){
        tot -= l[i] - l[i-1];
        rem += l[i] - r[i-1];
        while(ri < n-1 && rem > l[ri+1] - r[ri]){
            rem -= l[ri+1] - r[ri];
            ri++;
            tot += r[ri] - r[ri-1];
        }
        res= max(tot + rem, res);
    }
    cout << res << endl;

}