#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MAX 32

bitset<MAX> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<MAX; i+=2)
        prime[i] = 0;
    for (int p=3; p<MAX; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p*p; i<MAX; i+=2*p)
                prime[i] = 0;
        }
}

//int a[1000], color[1000];
//bool divisible[1000][200];
//vector<int> adj[1000];
//
//void dfs(int u, int sz = 0) {
//    for (int v : adj[u]) {
//        if (!color[v])
//            dfs(v, sz + 1);
//    }
//}

//pair<int, int> a[1000];
int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> numD(n);
//        for (int i=0; i<n; i++) {
//            adj[i].clear();
//            for (int j=0; j<primeList.size(); j++)
//                divisible[i][j] = false;
//        }
        for (int i=0; i<n; i++) {
            cin >> a[i];
//            cin >> a[i].first;
//            a[i].second = i;
//            for (int p : primeList)
//                if (a[i].first % p == 0)
//                    numD[i]++;
//            vector<bool> connect(n);
//            for (int j=0; j<primeList.size(); j++) {
//                divisible[i][j] = (a[i] % primeList[j] == 0);
//                for (int k=0; k<i; k++)
//                    if (divisible[i][j] && divisible[k][j])
//                        connect[k] = true;
//            }
//            for (int k=0; k<n; k++)
//                if (connect[k]) {
//                    adj[i].push_back(k);
//                    adj[k].push_back(i);
//                }
        }

//        memset(color, 0, sizeof(color));
//        for (int i=0; i<n; i++)
//            if (!color[i])
//                dfs(i);

//        sort(a, a + n, [&] (const pair<int, int> &pa, const pair<int, int> &pb) {
//            return numD[pa.second] > numD[pb.second];
//        });

        vector<int> color(n);
//        int m = 1;
//        for (int i=0; i<n; i++) {
//            for (int c=1; c<m; c++) {
//                bool ok = true;
//                for (int j : others[c])
//                    if (__gcd(a[i].first, j) == 1) {
//                        ok = false;
//                        break;
//                    }
//                if (ok) {
//                    color[a[i].second] = c;
//                    break;
//                }
//            }
//            if (!color[a[i].second])
//                color[a[i].second] = m++;
//            others[color[a[i].second]].push_back(a[i].first);
//        }

        vector<vector<int>> bucket(12);
        for (int i=0; i<n; i++) {
            for (int j=0; j<primeList.size(); j++) {
                if (a[i] % primeList[j] == 0) {
                    bucket[j].push_back(i);
                    break;
                }
            }
        }

        int m = 0, cnt = 0;
        for (int i=0; i<primeList.size(); i++) {
            if (!bucket[i].empty()) {
                m++;
                for (auto g : bucket[i])
                    color[g] = m;
            }
        }

        //assert(m <= 12);
        cout << m << "\n";
        for (int i=0; i<n; i++)
            cout << color[i] << " ";
        cout << "\n";
    }

    return 0;
}