#include<bits/stdc++.h>
using namespace std;

typedef pair <int, char> pic;

#define N 100010

char s[N], p[N];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s%s", s, p);
    vector <pic> v;
    for(int i = n-1, j = n-1; i >= 0; i = j) {
        while(j >= 0 && s[i] == s[j]) j --;
        v.push_back(pic(i-j, s[i]));
    }
    vector <int> ans;
    for(int i = n-1, k = 0; i >= 0; i --) {
        if(v[k].second == p[i]) {
            if(v[k].first == 1) k ++;
            else v[k].first --;
        }
        else {
            if(k == v.size()-1) {
                v[k].first --;
                v[k].second = '0' + '1' - v[k].second;
                ans.push_back(i);
            }
            else {
                ans.push_back(i - v[k].first);
                ans.push_back(i);
                v.push_back(pic(v[k].first, '0'+'1'-v[k].second));
                int m = v.size();
                if(v[m-2].second == v[m-1].second) {
                    v[m-2].first += v[m-1].first;
                    v.pop_back();
                }
                k ++;
                v[k].first --;
                if(v[k].first == 0) k ++;
            }
        }
    }
    printf("%d", ans.size());
    for(auto x : ans) printf(" %d", x+1);
    puts("");
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) solve();
}