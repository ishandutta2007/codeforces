#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;
LL n , K;
int cnt;
vector<int> a;
void dfs(int k , int x , int large) {
    if (k == 7) {
        ++ cnt;
        a.push_back(x);
        return;
    }
    for (int i = 0 ; i < 10 ; ++ i) {
        if (large > 1) {
            int a = x % 10 , b = x / 10 % 10;
            if (b > a && i <= a) continue;
            if (b < a && i >= a) continue;
        } else if (large == 1) {
            if (i == x % 10) continue;
        }
        dfs(k + 1 , x * 10 + i , large + (i > 0));
    }
}
vector< pair<LL , int> > V[20];
void DFS(int k , int x) {
    if (k == 7) {
        int j = x / 1000000;
        int k = x / 100000 % 10;
        if (j > k)
            j += 10;
        V[j].push_back(make_pair(x % n , x));
        return;
    }
    for (int i = 0 ; i < 10 ; ++ i) {
        if (k > 1) {
            int a = x % 10 , b = x / 10 % 10;
            if (b > a && i <= a) continue;
            if (b < a && i >= a) continue;
        } else if (k == 1) {
            if (i == x % 10) continue;
        }
        DFS(k + 1 , x * 10 + i);
    }
}

int main() {
    int i , j , k , l , x;
    dfs(0 , 0 , 0);
    cin >> n >> K;
    for (i = 1 ; i < cnt ; ++ i) {
        if (a[i] % n == 0) {
            if (!-- K) {
                cout << a[i] << endl;
                return 0;
            }
        }
    }
    DFS(0 , 0);
    for (j = 0 ; j < 20 ; ++ j)
        sort(V[j].begin() , V[j].end());
    for (i = 1 ; i < cnt ; ++ i) {
        x = a[i];
        j = x % 10 , k = x / 10 % 10;
        LL p = (n - (x * 10000000LL) % n) % n;
        if (x < 10) {
            for (l = 0 ; l < x ; ++ l) {
                int L = lower_bound(V[l].begin() , V[l].end() , make_pair(p , -1 << 30)) - V[l].begin();
                int R = upper_bound(V[l].begin() , V[l].end() , make_pair(p ,  1 << 30)) - V[l].begin();
                if (K - (R - L) <= 0) {
                    for (i = L ; i < R ; ++ i) {
                        if (!-- K) {
                            cout << x * 10000000LL + V[l][i].second << endl;
                            return 0;
                        }
                    }
                    assert(0);
                } else {
                    K -= R - L;
                }
            }
            for (l = x + 11 ; l < 20 ; ++ l) {
                int L = lower_bound(V[l].begin() , V[l].end() , make_pair(p , -1 << 30)) - V[l].begin();
                int R = upper_bound(V[l].begin() , V[l].end() , make_pair(p ,  1 << 30)) - V[l].begin();
                if (K - (R - L) <= 0) {
                    for (i = L ; i < R ; ++ i) {
                        if (!-- K) {
                            cout << x * 10000000LL + V[l][i].second << endl;
                            return 0;
                        }
                    }
                    assert(0);
                } else {
                    K -= R - L;
                }
            }
        } else {
            if (j > k) {
                for (l = 0 ; l < j ; ++ l) {
                    int L = lower_bound(V[l].begin() , V[l].end() , make_pair(p , -1 << 30)) - V[l].begin();
                    int R = upper_bound(V[l].begin() , V[l].end() , make_pair(p ,  1 << 30)) - V[l].begin();
                    if (K - (R - L) <= 0) {
                        for (i = L ; i < R ; ++ i) {
                            if (!-- K) {
                                cout << x * 10000000LL + V[l][i].second << endl;
                                return 0;
                            }
                        }
                        assert(0);
                    } else {
                        K -= R - L;
                    }
                }
            } else {
                for (l = j + 11 ; l < 20 ; ++ l) {
                    int L = lower_bound(V[l].begin() , V[l].end() , make_pair(p , -1 << 30)) - V[l].begin();
                    int R = upper_bound(V[l].begin() , V[l].end() , make_pair(p ,  1 << 30)) - V[l].begin();
                    if (K - (R - L) <= 0) {
                        for (i = L ; i < R ; ++ i) {
                            if (!-- K) {
                                cout << x * 10000000LL + V[l][i].second << endl;
                                return 0;
                            }
                        }
                        assert(0);
                    } else {
                        K -= R - L;
                    }
                }
            }
        }
    }
    puts("-1");
    return 0;
}