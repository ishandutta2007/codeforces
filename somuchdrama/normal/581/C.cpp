#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 1;
int arr[MAXN];

bool comp(int a, int b) {
    return (a % 10 > b % 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
        
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    sort(arr, arr+n, comp);
    
    for (int i = 0; i < n; ++i) {
        if (!(arr[i] % 10))
            break;
        int rest = min(k, 10 - arr[i] % 10); 
        arr[i] += rest;
        k -= rest;        
    }
    
    for (int i = 0; i < n; ++i) {
        int pl = min(100-arr[i], k);
        arr[i] += pl;
        k -= pl;
        if (!k)
            break;
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i] / 10;
    cout << sum;  
    
    return 0;
}