#include<bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, a[N];
vector<int> v;

void print(vector<int> &x) {
    for(int i = 0; i < x.size(); i ++) printf("%d%c", x[i], ".\n"[i == x.size() - 1]);
}

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        v.clear();
        v.push_back(1);
        print(v);
        for(int i = 1; i < n; i ++) {
            if(a[i] == 1) v.push_back(1);
            else {
                while(v.back() != a[i] - 1) v.pop_back();
                v.pop_back();
                v.push_back(a[i]);
            }
            print(v);
        }
    }
}