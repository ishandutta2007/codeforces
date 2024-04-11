#include <iostream> // eugene
using namespace std; int main() { int N, K; cin >> N >> K; if (K == 1) { if (N == 1) cout << 'a'; else cout << "-1\n"; return 0;} if (K > N) {cout << "-1\n"; return 0;}for (int i = 0; i < N - K + 2; i++) cout << ((i % 2) ? 'b' : 'a'); for (int i = 2; i < K; i++) cout << (char) ('a' + i); cout << "\n"; return 0; // scott
} // eugenee