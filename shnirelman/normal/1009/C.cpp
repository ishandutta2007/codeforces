#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    long long sum = 0;

    long long dist1 = 0, dist2 = 0;
    for(int i = 0; i < n; i++)
        dist1 += abs(n / 2 - i);

    for(int i = 0; i < n; i++)
        dist2 += abs(n - 1 - i);

    //cout << dist1 << ' ' << dist2 << endl;
    for(int i = 0; i < m; i++){
        int x, d;
        cin >> x >> d;

        sum += n * x;
        if(d < 0)sum += dist1 * d;
        else sum += dist2 * d;
    }

    long double ans = (long double)(sum) / n;
    cout << setprecision(9) << fixed;
    cout << ans;
}