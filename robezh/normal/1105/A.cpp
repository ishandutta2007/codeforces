#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;

int n;
int a[N];

int check(int t) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= t + 1) sum += a[i] - (t + 1);
        else if(a[i] <= t - 1) sum += (t - 1) - a[i];
    }
    return sum;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = (int)1e9, t = -1;
    for(int i = 1; i <= 100; i++) {
        int cursum = check(i);
        if(cursum < sum){
            sum = cursum;
            t = i;
        }
    }
    cout << t << " " << sum << endl;
}