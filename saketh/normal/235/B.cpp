#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

int N;
double prob[100005];

int main(){
    setup();
    cin >> N;

    double ans = 0;
    double exv = 0;

    for(int i=0; i<N; i++){
        cin >> prob[i];
        ans += prob[i] * (2 * exv + 1);
        exv = prob[i] * (1 + exv);
    }

    cout << ans << "\n";
}