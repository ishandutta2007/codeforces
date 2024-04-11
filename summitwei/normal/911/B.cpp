#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int maxNum = 0;
    for(int i=1; i<N; i++){
        int minA = A/i;
        int minB = B/(N-i);
        int minTotal = min(minA, minB);
        if(minTotal > maxNum){
            maxNum = minTotal;
        }
    }

    cout << maxNum;
    return 0;
}