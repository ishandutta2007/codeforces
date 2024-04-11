#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    map<pair<int, int>, int> m;
    int cnt = 0;
    for(int i = 0; i < n; i++)if(a[i] != 0){
        int g = gcd(a[i], b[i]);
        if(m.count({b[i] / g, a[i] / g}))m[{b[i] / g, a[i] / g}]++;
        else m[{b[i] / g, a[i] / g}] = 1;
    }
    else{
        if(b[i] == 0){
            cnt++;
        }
    }

    int mx = 0;
    for(map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); it++)mx = max(mx, it -> second);

    cout << mx + cnt;
}