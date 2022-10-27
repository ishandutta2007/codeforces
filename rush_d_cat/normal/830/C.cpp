#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int n; LL k;
LL a[102];
vector<LL> v;
LL max(LL x, LL y) {return x<y?y:x;}
LL min(LL x, LL y) {return x>y?y:x;}
int main() {
    cin >> n >> k;
    LL sum_a = 0, mx = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i]; sum_a += a[i]; mx = max(mx, a[i]);
    }

    for(int i=1;i<=n;i++) {
        for(LL t=1;t*t<=a[i];t++) {
            v.push_back(t); v.push_back(a[i]/t);
        }
    }

    sort(v.begin(), v.end());

    LL d = 1; 
    if((k+sum_a)/n >= mx) d = max(d, (k+sum_a)/n);

    for(int i=0;i<v.size()-1;i++) {
        int l = v[i], r = v[i+1];
        if(l == r) continue;

        LL sum = 0;
        for(int i=1;i<=n;i++) {
            sum += (a[i] + l - 1) / l; 
        }
        if(sum * l <= k+sum_a) d = max(l, d);

        sum = 0;
        for(int i=1;i<=n;i++) {
            sum += (a[i] + r - 1) / r; 
        }
        if(sum * r <= k+sum_a) d = max(r, d);

        if(r - l == 1) continue;
        sum = 0;
        for(int j=1;j<=n;j++)  {
            sum += (a[j] + r - 2) / (r - 1);
        }

        LL temp = (k+sum_a) / sum;
        if(temp <= l) continue;
        if(sum) d = max(d, min(r-1, temp));
        else d = max(d, r-1); 
    }
    cout << d << endl;
}