#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e6 + 50, mod = (int)51123987, inv2 = (mod + 1) / 2;

struct link{
    int head[N];int nxt[N];int to[N];char edge[N];
    int cnt = 0;

    link(){
        init();
    }

    void init(){
        memset(head,-1, sizeof(head));
        memset(nxt,-1, sizeof(head));
        cnt = 0;
    }

    void insert(int f,int t,char e){
        int cur = cnt++;
        nxt[cur] = head[f];
        head[f] = cur;
        to[cur] = t;
        edge[cur] = e;
    }

    int get_edge(int f,char e){
        for(int i = head[f];i!=-1;i=nxt[i]){
            if(edge[i] == e)return to[i];
        }
        return 0;
    }
} _list;

int res[2][N];

struct PAM {
    const static int N = (int)2e6 + 50;

    struct node {
        int len;
//        map<int, int> nxt;
        int fail;
        node(int len = 0): len(len), fail(0) {
//            memset(nxt, 0, sizeof(nxt));
//            nxt.clear();
        }
    } nd[N];

    int len, cnt;
    int cur;
    char s[N];
    int sum[N];
    int tcnt[N];
    int loc[N];

    int getfail(int x) {
        while(s[len - nd[x].len - 1] != s[len]) x = nd[x].fail;
        return x;
    }

    void init(int n) {
        _list.init();
        fill(tcnt, tcnt + n + 2, 0);
        fill(sum, sum + n + 2, 0);
        len = cnt = cur = 0;
        nd[cnt] = node(0);
        nd[cnt].fail = 1;
        nd[++cnt] = node(-1);
        nd[cnt].fail = 0;
        s[0] = '$';
    }

    void extend(char c, int i) {
        s[++len] = c;
        int now = getfail(cur);
        if(!_list.get_edge(now, c)) {
            int tmp = ++cnt;
            nd[tmp] = node(nd[now].len + 2);
            nd[tmp].fail = _list.get_edge(getfail(nd[now].fail), c);
            _list.insert(now, tmp, c);
//            nd[now].nxt[c - 'a'] = tmp;
        }
        cur = _list.get_edge(now, c);
//        cur = nd[now].nxt[c - 'a'];
        sum[cur]++;
        loc[i] = cur;
    }

    void calc(int id) {
        for(int i = 2; i <= cnt; i++) {
            tcnt[i] = 1 + tcnt[nd[i].fail];
        }
        for(int i = cnt; i >= 2; i--) {
            sum[nd[i].fail] += sum[i];
        }

        for(int i = 1; i <= len; i++) {
            res[id][i] = tcnt[loc[i]];
            if(!id) res[id][i] += res[id][i-1], res[id][i] %= mod;
        }
    }
} pam;

//string str;
char str[N];
int len;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    scanf("%d", &len);
    scanf("%s", str);
    for(int id = 0; id < 2; id++) fill(res[id], res[id] + len + 2, 0);
    pam.init(len);
    for(int i = 0; i < len; i++) pam.extend(str[i], i + 1);
    pam.calc(0);

    pam.init(len);
    for(int i = len - 1; i >= 0; i--) pam.extend(str[i], i + 1);
    pam.calc(1);

    ll fres = 0;
    ll tcnt = 0;
    for(int i = 2; i <= pam.cnt; i++) tcnt += pam.sum[i], tcnt %= mod;
    fres = 1LL * (tcnt) * (tcnt - 1) % mod * inv2 % mod;
    for(int i = 1; i <= len - 1; i++) {
        fres -= (1LL * res[0][i] * res[1][i+1]);
        fres %= mod;
    }
    cout << (fres + mod) % mod << "\n";


}