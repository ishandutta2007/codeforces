#include <iostream> //scott
#include <cstdio> // alex darn too many typos
#include <algorithm> //scott wait rofl this is just 3^(N-1) (N = 0 is 1 tho)

using namespace std; // alex hmm still reading prob but darn this might be a pretty silly prob

int main() { //scott i'm pretty confident about this
    int N; //alex woohoo go for it
    cin >> N; //scott
    int mod = 1000003; //alex
    int ans = 1; //scott
    for (int i = 0; i < N - 1; i++) { //alex
        ans = (3 * ans) % mod; //scott
    } //alex
    cout << ans << "\n"; //scott
    return 0; //alex
} //scott GG