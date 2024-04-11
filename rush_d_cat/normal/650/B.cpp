#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;

const int NICO = 1002;

int n, a, b, T;
char s[500000+10];

char str[1000000+10];
int  sum[1000000+10];

int cac(int L, int R) 
{
    
    if(R - n > n - L) {
        return (sum[R] - sum[L-1]) * b + (R - L + 1) + (R - L) * a + (n - L) * a;
    } else {
        return (sum[R] - sum[L-1]) * b + (R - L + 1) + (R - L) * a + (R - n) * a;
    }

}

int main() {
    cin >> n >> a >> b >> T;

    scanf("%s", s+1);
    
    for(int i = n; i <= 2*n - 1; i ++) {
        str[i] = s[i - n + 1];
    }
    for(int i = 1; i <= n-1; i ++) {
        str[i] = s[i + 1];
    }

    for(int i = 1; i <= 2*n - 1; i ++) {
        sum[i] = sum[i-1] + (str[i] == 'w' ? 1 : 0);
    }

    int ans = 0;

    for(int L=n, R=2*n-1; L >= 1 && R >= n; L--) 
    {
        while(R >= n && cac(L, R) > T) R --;
        //printf("%d %d %d\n", L, R, cac(L, R));
        ans = max(R-L+1, ans);
    }

    ans = min(ans, n);

    cout << ans << endl;
}