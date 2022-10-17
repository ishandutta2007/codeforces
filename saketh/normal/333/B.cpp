#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;
bool bx[1028], by[1028];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        bx[x-1] = true;
        by[y-1] = true;
    }

    int A = 0;
    for (int i = 1; i+1 < N; i++) {
        if(!bx[i]) A++;
        if(!by[i]) A++;
    }

    if(N&1 && !bx[N/2] && !by[N/2]) A--;

    cout << A << endl;

}