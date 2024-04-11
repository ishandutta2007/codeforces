#include<bits/stdc++.h>
using namespace std;

vector <string> v;
map <string, int> mp;
int a[110];

bool cmp(string s, string t) {
    return mp[s] > mp[t];
}

int main() {
    char s[40];
    int n, m, i, ans_max, ans_min;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i ++) scanf("%d", a + i); sort(a + 1, a + n + 1);
    while(m --) {
        scanf("%s", s);
        if(mp[s]) mp[s] ++;
        else mp[s] = 1, v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(ans_min = ans_max = i = 0; i < v.size(); i ++) ans_min += mp[v[i]] * a[i + 1], ans_max += mp[v[i]] * a[n - i];
    printf("%d %d\n", ans_min, ans_max);
    return 0;
}