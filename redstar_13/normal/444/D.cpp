#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

VI pos[1000100];

int get_val(string s) {
    int val=0;
    for (int i=0; i<s.length(); i++) val=val*28+s[i]-'a'+1;
    return val;
}

const int limit = 333;
map<INT, int> mp;
vector<int> :: iterator it;

inline void smin(int &x, const int &y) {if (x>y) x=y;}

int calc(string s1, string s2) {
    int val1=get_val(s1), val2=get_val(s2);
    if (pos[val1].empty() || pos[val2].empty()) return -1;
    if (pos[val1].size()>pos[val2].size()) swap(val1, val2), swap(s1, s2);
    int ans=int(1e9);
    INT id = ((INT)val1<<20)+val2;
    if (mp.count(id)) return mp[id];
    if (pos[val1].size()<limit) {
        for (int v : pos[val1]) {
            it=lower_bound(pos[val2].begin(), pos[val2].end(), v);
            if (it!=pos[val2].end()) smin(ans, max((*it)+s2.length(), v+s1.length())-v);
            if (it!=pos[val2].begin()) {
                --it;
                smin(ans, max((*it)+s2.length(), v+s1.length())-(*it));
            }
        }
    } else {
        int i=0;
        for (int v : pos[val1]) {
            while (i<pos[val2].size() && pos[val2][i]<v) i++;
            if (i<pos[val2].size()) smin(ans, max(pos[val2][i]+s2.length(), v+s1.length())-v);
            if (i) smin(ans, max(pos[val2][i-1]+s2.length(), v+s1.length())-pos[val2][i-1]);
            if (i==pos[val2].size()) break;
        }
    }
    return mp[id]=ans;
}

char s1[11], s2[11], s[50505];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    scanf("%s", s);
    int n=strlen(s), q;
    for (int i=0; i<n; i++) {
        for (int L=1; L<=4; L++) {
            if (i+L>n) break;
            int val=0;
            for (int j=0; j<L; j++) val=val*28+s[i+j]-'a'+1;
            pos[val].push_back(i);
        }
    }

    for (scanf("%d", &q); q--; ) {
        scanf("%s%s", s1, s2);
        printf("%d\n", calc(s1, s2));
    }

    return 0;
}