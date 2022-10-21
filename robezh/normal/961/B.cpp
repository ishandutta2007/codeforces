#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100050], t[100050];

int main() {
    cin >> n >> k;
    int osum = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){cin >> t[i]; if(t[i]) osum += a[i];}
    int nsum = 0;
    int maxnsum = 0;
    for(int i = 0; i < k; i++){if(!t[i]) nsum += a[i]; maxnsum = nsum;}
    for(int i = k; i < n; i++){
        if(!t[i-k]) nsum -= a[i-k];
        if(!t[i]) nsum += a[i];
        maxnsum = max(maxnsum, nsum);
    }
    cout << maxnsum + osum;


}