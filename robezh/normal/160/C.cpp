#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, num[100050];
ll k;

int main(){
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num, num+n);
    int a = num[k/n];
    int l = lower_bound(num, num+n, a) - num;
    int r = upper_bound(num, num+n, a) - num;
    k -= (ll)n * l;
    int b = num[k/(r-l)];
    cout << a << " " << b << endl;
}