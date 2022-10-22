#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long LL;

int n , m, a[N];
int s[N] , g[N];
vector<vector<int>> res;
set<pair<int , int>> pa;
bool over;
int main() {
    int K = 0;
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand() % (1000000 / m) + 1;
        K += a[i];
        pa.insert(make_pair(a[i] , i));
    }
    K = (K + n - 1) / n;

    printf("%d\n" , K);

    if (m == 1) {
        g[0] = n;
        for (int i = 0 ; i < m ; ++ i) {
            printf("%d%c" , g[i] , " \n"[i + 1 == m]);
        }
        for (int j = 0 ; j < K ; ++ j) {
            for (int i = 0 ; i < m ; ++ i) {
                printf("%d%c" , 1 , " \n"[i + 1 == m]);
            }
        }
        return 0;
    }

    for (int i = 0 ; i < K ; ++ i) {
        res.emplace_back(vector<int>(m));
    }

    for (int j = 0 ; j < m ; ++ j) {
        int i , x;
        for (i = 1 ; i <= a[j] ; i = x + 1) {
            int w = a[j] / i;
            x = a[j] / w;
            // [i , x] -> a[j] / i
            for (int k = i ; k < N ; k += k & -k) {
                s[k] += w;
            }
            for (int k = x + 1 ; k < N ; k += k & -k) {
                s[k] -= w;
            }
        }
    }

    int rr = N - 1;

    for (int i = 0 ; i < m && n ; ++ i) {
        int l = 1 , r = n;

        if (over) r = 1;

        while (rr > 1) {
            int sum = 0;
            for (int k = rr ; k > 0 ; k -= k & -k) {
                sum += s[k];
            }
            if (sum >= K) break;
            -- rr;
        }

        l = rr;
        g[i] = l;
        n -= l;

        if (l == 1) {
            over = 1;
        }

        int re = K , id = 0;
        auto it = pa.rbegin();
        vector<pair<int , int>> v;
        if (!over) {


            while (re && it != pa.rend()) {
                int w = it->first;
                while (re && w >= l) {
                    -- re;
                    w -= l;
                    res[id ++][i] = it->second;
                }
                v.emplace_back(it->second, w);
                it ++;
            }
        } else {
            for (int j = i + 1 ; j < m ; ++ j) {
                g[j] = n ? 1 : 0;
                if (g[j]) -- n;
            }
            int vvv = i , pp = 0;
            for (int j = 0 ; j < m ; ++ j) {
                while (a[j]) {
                    -- a[j];
                    if (pp == K) {
                        pp = 0, ++ vvv;
                    }
                    res[pp ++][vvv] = j;
                }
            }
            break;
        }

        for (auto &it : v) {
            int j = it.first , i , x;
            if (!over) {
                for (i = 1 ; i <= a[j] ; i = x + 1) {
                    int w = a[j] / i;
                    x = a[j] / w;
                    // [i , x] -> a[j] / i
                    for (int k = i ; k < N ; k += k & -k) {
                        s[k] -= w;
                    }
                    for (int k = x + 1 ; k < N ; k += k & -k) {
                        s[k] += w;
                    }
                }
            }
            pa.erase(make_pair(a[j] , j));
            a[j] = it.second;
            if (a[j] < 0) continue;
            pa.insert(make_pair(a[j] , j));

            if (!over) {
                for (i = 1 ; i <= a[j] ; i = x + 1) {
                    int w = a[j] / i;
                    x = a[j] / w;
                    // [i , x] -> a[j] / i
                    for (int k = i ; k < N ; k += k & -k) {
                        s[k] += w;
                    }
                    for (int k = x + 1 ; k < N ; k += k & -k) {
                        s[k] -= w;
                    }
                }
            }
        }

        //cout << l << endl;
        g[i] = l;
        /*for (int i = 0 ; i < m ; ++ i) {
          cout << a[i] << ' ';
          } cout << endl;*/
    }
    g[0] += n;

      for (int i = 0 ; i < m ; ++ i) {
  printf("%d%c" , g[i] , " \n"[i + 1 == m]);
  }
  for (int j = 0 ; j < K ; ++ j) {
  for (int i = 0 ; i < m ; ++ i) {
  printf("%d%c" , 1 + res[j][i] , " \n"[i + 1 == m]);
  }
  }

    for (int i = 0 ; i < m ; ++ i) {
        assert(a[i] <= 0);
    }
}