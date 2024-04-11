#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int M, N;
unsigned long long a[100005], as = 0;
unsigned long long b[100005], bs = 0;

int main(){
    cin >> M >> N;
    
    for(int i=0; i<M; i++){
        cin >> a[i];
        as += a[i];
    }
    for(int i=0; i<N; i++){
        cin >> b[i];
        bs += b[i];
    }

    sort(a, a+M, greater<int>());
    sort(b, b+N, greater<int>());

    unsigned long long ans = 1LL << 62;

    unsigned long long sum = 0;
    for(unsigned long long st = 1; st<=M; st++){
        sum += a[st-1];
        ans = min(ans, as - sum + st * bs);
    }

    sum = 0;
    for(unsigned long long st = 1; st<=N; st++){
        sum += b[st-1];
        ans = min(ans, bs - sum + st * as);
    }

    cout << ans << endl;
    return 0;
}