#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n , m;
map<string , int> h;
string name[N] , str[N] , re[N];
bool f[N][N];
int g[N][N];

void print(int x , int y) {
    if (x == 0) {
        return;
    }
    print(x - 1 , g[x][y]);
    cout << name[y] << re[x - 1] << endl;
}

void work() {
    scanf("%d" , &n);
    h.clear();
    for (int i = 0 ; i < n ; ++ i) {
        cin >> name[i];
        h[name[i]] = i;
    }
    scanf("%d\n" , &m);
    memset(f , 0 , sizeof(f));
    memset(g , 0 , sizeof(g));
    f[0][n] = 1;
    for (int i = 0 ; i < m ; ++ i) {
        getline(cin , str[i]);
        re[i].clear();
    }
    for (int i = 0 ; i < m ; ++ i) {
        string usr , buf = str[i];
        int p = 0;
        while (p < buf.size() && buf[p] != ':') {
            usr += buf[p ++];
        }
        int q = p;
        while (q < buf.size()) {
            re[i] += buf[q ++];
        }
        set<int> mention;
        while (p < buf.size()) {
            string word;
            while (p < buf.size() && isalnum(buf[p])) {
                word += buf[p ++];
            }
            if (h.count(word)) {
                mention.insert(h[word]);
            }
            if (p < buf.size()) ++ p;
        }
        if (usr == "?") {
            for (int j = 0 ; j <= n ; ++ j) {
                if (!f[i][j]) continue;
                for (int k = 0 ; k < n ; ++ k) {
                    if (mention.count(k) || k == j) continue;
                    f[i + 1][k] = 1;
                    g[i + 1][k] = j;
                }
            }
        } else {
            if (!h.count(usr)) {
                puts("Impossible");
                return;
            }
            int id = h[usr];
            if (!mention.count(id)) {
                for (int j = 0 ; j <= n ; ++ j) {
                    if (f[i][j] && id != j) {
                        f[i + 1][id] = 1;
                        g[i + 1][id] = j;
                    }
                }
            }
        }
    }
    int x = -1;
    for (int i = 0 ; i < n ; ++ i) {
        if (f[m][i]) {
            x = i;
        }
    }
    if (x == -1) {
        puts("Impossible");
    } else {
        print(m , x);
    }
}

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {
        work();
    }
}