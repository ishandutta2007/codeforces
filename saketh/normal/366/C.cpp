#include<iostream>
using namespace std;

int N, K;
int taste[105];
int calor[105];
int max_taste[105][20005];

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> taste[i];
    for(int i=0; i<N; i++)
        cin >> calor[i];

    for(int diff = -10000; diff <= 10000; diff++)
        max_taste[0][diff + 10000] = -1;
    max_taste[0][10000] = 0;

    for(int i=0; i<N; i++){
        int contrib = taste[i] - K * calor[i];
        for(int diff = -10000; diff <= 10000; diff++){
            max_taste[i+1][diff + 10000] = max_taste[i][diff + 10000];
            int prev_diff = diff - contrib;
            if(prev_diff < -10000 || prev_diff > 10000) continue;
            if(max_taste[i][prev_diff + 10000] == -1) continue;
            max_taste[i+1][diff + 10000] =
                max(max_taste[i+1][diff + 10000], taste[i] + max_taste[i][prev_diff + 10000]);
        }
    }

    if(max_taste[N][10000])
        cout << max_taste[N][10000] << endl;
    else cout << -1 << endl;
    return 0;
}