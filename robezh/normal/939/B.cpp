#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int k;
ll a[100050];

int main() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> a[i];

    int maxi = 0;
    for(int i = 0; i < k; i++){
        ll maxnow = n / a[maxi] * a[maxi];
        if(n/a[i]*a[i] > maxnow) maxi = i;
    }
    cout << maxi+1 << " " << n/a[maxi];

}