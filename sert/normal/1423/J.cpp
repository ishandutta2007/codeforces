#include <iostream>
using namespace std;
 
typedef long long ll;

const int MD = (int)1e9 + 7;
inline void add(int &a, int b) {
    a += b;
    if (a >= MD) a -= MD;
}
inline void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += MD;
}
 
const int N = 13;

bool isspace(char c) {
	return c == ' ' || c == '\n';
}
 
ll readLL() {
	ll x = 0;
	char c = ' ';
	while(isspace(c)) c = _getchar_nolock();
	while(!isspace(c)) {
		x = 10 * x + (int)(c - '0');
		c = _getchar_nolock();
	}
	return x;
}
 
 
int main() {
    int t = readLL();
    
    int dp[N];
    int dp2[N];
    while (t--) {
        long long x = readLL();
        //x = 1000000000; x *= x;
        for (int i = 0; i < N; i++) dp[i] = 0;
        dp[0] = 1;
 
        while (x > 0) {
            int sum = 0;
            int cur = x % 2 * 2;
            if (cur == 2) sum = dp[0];
            for (int i = 0; i < N; i++) {
                if (cur < N) add(sum, dp[cur]); cur += 2;
                if (cur >= 18 && cur - 18 < N) sub(sum, dp[cur - 18]);
                dp2[i] = sum;
            }
 
            x /= 2;
            swap(dp, dp2);
        }
        cout << dp[0] << "\n";
    }
}