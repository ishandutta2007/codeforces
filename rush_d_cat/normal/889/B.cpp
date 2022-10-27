#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 100000+10;

char s[N];
int n, mp[1002][1002], in[1002], out[1002], nxt[1002], vis[1002], vis2[1002];

set<int> st;
vector<int> v[1002];
string str[1002];

bool cmp(string s1, string s2) {
    return (s1+s2) < (s2+s1);
}

int main() {
    scanf("%d", &n);
    
    bool flag = 1; 
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s + 1);

        st.clear(); 
        int len = strlen(s+1);
        for (int pos = 1; pos <= len; pos ++) {
            vis[s[pos]] = 1;
            st.insert(s[pos]);
            if (pos < len) mp[s[pos]][s[pos+1]] = 1;
        }
        if (st.size() != len) flag = 0;
    }

    for (int i = 'a'; i <= 'z'; i ++) {
        for (int j = 'a'; j <= 'z'; j ++) {
            if (mp[i][j]) {
                v[i].push_back(j);
                in[j] ++; out[i] ++;
            }
        }
    }

    for (int i = 'a'; i <= 'z'; i ++) {
        if (in[i] >= 2 || out[i] >= 2) flag = 0;
    }

    if (!flag) {
        printf("NO\n"); return 0;
    }

    int cnt = 1;

    vector<int> start;

    for (int i = 'a'; i <= 'z'; i ++) {
        if (in[i] == 0 && out[i] == 0 && vis[i]) {
            start.push_back(i);
        } 
        if (in[i] == 0 && out[i] == 1) {
            start.push_back(i);
        }
    }

    for (int i = 0; i < start.size(); i ++) {

        int cur = start[i];

        str[cnt] = "";
        str[cnt] = str[cnt] + (char)cur;
        vis2[cur] = 1;

        while (out[cur]) {
            out[cur] --;
            cur = v[cur][0];
            str[cnt] += cur;
            vis2[cur] = 1;
        }
        cnt ++;
    }
    //printf("%d\n", cnt);
    for (int i ='a'; i <= 'z'; i ++) {
        if (vis[i] == 1 && vis2[i] == 0) {
            printf("NO\n"); return 0;
        }
    }

    sort(str+1, str+cnt, cmp);
    for (int i=1;i<cnt;i++) {
        cout << str[i];
    }


}