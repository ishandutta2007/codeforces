#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
int a[64], b[64];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int H = 0, C = 0;

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (b[j] % a[i]) continue;
            if (b[j] / a[i] > H){ 
                H = b[j] / a[i];
                C = 1;
            }
            else if(b[j] / a[i] == H) C++;
        }
    }

    cout << C << endl;
}