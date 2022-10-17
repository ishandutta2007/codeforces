#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long vals[1000005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> vals[i];
    sort(vals, vals + N);

    long long ans = 0;
    for(int i=0; i<N; i++)
        ans += (i + 2) * vals[i];
    cout << ans - vals[N-1] << endl;
    return 0;
}