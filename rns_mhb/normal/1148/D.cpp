#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 300010

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]);
    vector <int> v, w;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > b[i]) v.push_back(a[i]);
        if(a[i] < b[i]) w.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    if(v.size() > w.size()) {
        cout << v.size() << endl;
        vector <pii> o;
        for(int i = 1; i <= n; i ++) if(a[i] > b[i]) o.push_back(pii(a[i], i));
        sort(o.begin(), o.end());
        int x = -1;
        for(int i = 0; i < o.size(); i ++) {
            if(o[i].first != x) {
                x = o[i].first;
                printf("%d ", o[i].second);
            }
        }
        puts("");
    }
    else {
        cout << w.size() << endl;
        vector <pii> o;
        for(int i = 1; i <= n; i ++) if(a[i] < b[i]) o.push_back(pii(a[i], i));
        sort(o.begin(), o.end());
        reverse(o.begin(), o.end());
        int x = -1;
        for(int i = 0; i < o.size(); i ++) {
            if(o[i].first != x) {
                x = o[i].first;
                printf("%d ", o[i].second);
            }
        }
        puts("");

    }
}