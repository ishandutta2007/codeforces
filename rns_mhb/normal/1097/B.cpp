#include<bits/stdc++.h>
using namespace std;

int n, a[20];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    vector <int> v, w;
    v.push_back(a[1]);
    for(int i = 2; i <= n; i ++) {
        w.clear();
        for(int j = 0; j < v.size(); j ++) {
            w.push_back(v[j] - a[i]);
            w.push_back(v[j] + a[i]);
        }
        swap(v, w);
    }
    for(int i = 0; i < v.size(); i ++) if(v[i] % 360 == 0) {
        puts("YES");
        return 0;
    }
    puts("NO");
}