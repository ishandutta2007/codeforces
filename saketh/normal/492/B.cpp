#include <iostream>
#include <algorithm>
using namespace std;

int N, L, v[1024];
double ans = 0;

int main(){
    cin >> N >> L;
    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v, v+N);
    ans = max(ans, (double) v[0]);
    ans = max(ans, (double)(L - v[N-1]));

    for(int i=1; i<N; i++)
        ans = max(ans, (v[i]-v[i-1])/2.0);

    cout.precision(20);
    cout << ans << endl;
    return 0;
}