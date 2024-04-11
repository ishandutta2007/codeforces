#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 3;

int n;
ll x[N], y[N];
vector<int> p;

ll get_side(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool check_angle(int i, int j, int k){
    ll s1 = get_side(x[i], y[i], x[j], y[j]);
    ll s2 = get_side(x[i], y[i], x[k], y[k]);
    ll s3 = get_side(x[j], y[j], x[k], y[k]);

    if(s2 > s1 && s2 > s3) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    p.push_back(1);
    p.push_back(2);
    for(int i = 3; i <= n; ++i){
        p.push_back(i);
        int idx = i - 1;
        while(idx >= 2){
            if(check_angle(p[idx - 2], p[idx - 1], p[idx]))
                break;

            swap(p[idx], p[idx - 1]);
            --idx;
        }
    }

    for(int x: p)
        cout << x << " ";
}