#include<bits/stdc++.h>
using namespace std;

int n, a[200010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int f = 0, s = 0;
    long long sum = 0;
    for(int i = 1; i <= n; i ++) if(a[i] > s) {
        s = a[i];
        if(s > f) swap(s, f);
    }
    sum = -f - s;
    for(int i = 1; i <= n; i ++) sum += a[i];
    vector <int> v;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == f) {if(s == sum) v.push_back(i);}
        else if(a[i] == s) {if(f == sum) v.push_back(i);}
        else if(sum - a[i] + s == f) v.push_back(i);
    }
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
    puts("");
}