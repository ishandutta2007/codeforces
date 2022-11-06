#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz], b[sz];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);

    vector <int> one;
    for(int i=0; i<n; i++) one.push_back(b[i]-a[i]);
    sort(one.begin(), one.end());

    ll ans=0;
    for(int i=0; i<n; i++) {
        int now=a[i]-b[i];
        ans += upper_bound(one.begin(), one.end(), now-1) - one.begin();
        if(a[i]>b[i]) ans--;
    }

    cout << ans/2;
}