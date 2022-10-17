#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, freq[26];
char C;

int main(){
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> C;
        freq[C-'A']++;
    }

    sort(freq, freq + 26);
    reverse(freq, freq + 26);

    long long ans = 0;
    for(int c=0; c<26; c++){
        long long take = min(freq[c], K);
        ans += take * take;
        K = max(0, K - freq[c]);
    }

    cout << ans << endl;
    return 0;
}