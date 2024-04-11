#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
LL n, minc = 1e15, maxc = -1e15;
void solve(LL a) {
    LL t = n / a;
    maxc = max(maxc, (a+1)*(t+2)*(LL)3 - n);
    LL tmp = (LL)sqrt(t) + 1;
    for(LL b = tmp; b >= 1; b--) {
        if(t % b == 0) {
            minc = min(minc, (a+1)*(b+2)*(t/b+2) - n);
        }
    }

}
int main()
{
    cin >> n;
    for(LL a = 1; a * a <= n; a ++)
    {
        if(n % a == 0) {
            solve(a);
            solve(n/a);
        }
    }
    cout << minc << " " << maxc << endl;
}