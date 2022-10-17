#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

int N, I;
int perm[3005];
double dp[3005 * 3005];

int main(){
    setup();

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> perm[i];
        for(int j=0; j<i; j++)
            if(perm[j] > perm[i])
                I++;
    }

    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<N*N; i++)
        dp[i] = 4 + dp[i-2];

    cout << dp[I] << endl;
}