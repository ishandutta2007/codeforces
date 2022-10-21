#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ratings[2 * N];
    for(int i = 0; i < 2*N; i++){
        cin >> ratings[i];
    }
    sort(ratings, ratings + 2*N);
    if(ratings[N-1] == ratings[N]){
        cout << "NO";
    }
    else cout << "YES";
}