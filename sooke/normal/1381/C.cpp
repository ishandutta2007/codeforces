#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, s, t, _s, _t, oc, a[N], k[N], ans[N];
std::priority_queue<std::pair<int, int>> que;
std::vector<int> p[N], q[N];

bool solveagain() {
    s = _s; t = _t;
    for (int c = 0; c <= n; c++) {
        p[c].clear(); q[c].clear();
    }
    for (int i = 0; i < n; i++) {
        p[a[i]].push_back(i);
    }
    int max = 0, lim;
    for (; !que.empty(); que.pop());
    for (int c = 0; c <= n; c++) {
        k[c] = p[c].size();
        if (k[c] == 0) { oc = c; }
        max = std::max(max, k[c]);
    }
    if (max > n - max) {
        lim = (n - max) * 2;
        for (int c = 0; c <= n; c++) {
            if (k[c] == max) {
                while (k[c] > n - max) {
                    if (s > 0) {
                        s--; t--;
                        q[c].push_back(c);
                    } else {
                        q[c].push_back(oc);
                    }
                    k[c]--;
                }
            }
        }
    } else {
        lim = n;
    }
    int sum = 0;
    for (int c = 0; c <= n; c++) {
        que.push({k[c], c});
        sum += k[c];
    }
    if (sum % 2 == 0) {
        int c = que.top().second; que.pop();
        if (k[c] == 0) {
            que.push({k[c], c});
        } else {
            if (s > 0) {
                s--; t--;
                q[c].push_back(c);
            } else {
                q[c].push_back(oc);
            }
            que.push({--k[c], c});
        }
        while (true) {
            int x = que.top().second; que.pop();
            int y = que.top().second; que.pop();
            if (que.empty()) {
                que.push({k[x], x});
                que.push({k[y], y});
                break;
            }
            int z = que.top().second; que.pop();
            if (k[z] == 0) {
                que.push({k[x], x});
                que.push({k[y], y});
                que.push({k[z], z});
                break;
            }
            if (s % 2 == 1 && s >= 3) {
                s -= 3; t -= 3;
                q[x].push_back(x);
                q[y].push_back(y);
                q[z].push_back(z);
            } else if (s % 2 == 1) {
                s--;
                if (t >= 3) {
                    t -= 3;
                    q[x].push_back(x);
                    q[y].push_back(z);
                    q[z].push_back(y);
                } else if (t >= 2) {
                    t -= 2;
                    q[x].push_back(x);
                    q[y].push_back(z);
                    q[z].push_back(oc);
                } else {
                    t--;
                    q[x].push_back(x);
                    q[y].push_back(oc);
                    q[z].push_back(oc);
                }
            } else if (t % 2 == 1 && t - 3 >= s) {
                t -= 3;
                q[x].push_back(y);
                q[y].push_back(z);
                q[z].push_back(x);
            } else if (t % 2 == 1) {
                t--;
                q[x].push_back(oc);
                q[y].push_back(x);
                q[z].push_back(oc);
            } else if (t > 0 && s > 0) {
                s -= 2; t -= 2;
                q[x].push_back(x);
                q[y].push_back(y);
                q[z].push_back(oc);
            } else if (t > 0) {
                t -= 2;
                q[x].push_back(y);
                q[y].push_back(x);
                q[z].push_back(oc);
            } else {
                q[x].push_back(oc);
                q[y].push_back(oc);
                q[z].push_back(oc);
            }
            que.push({--k[x], x});
            que.push({--k[y], y});
            que.push({--k[z], z});
            break;
        }
    }
    while (true) {
        int x = que.top().second; que.pop();
        int y = que.top().second; que.pop();
        if (k[x] == 0 || k[y] == 0) { break; }
        if (k[y] == 0) {
            if (s > 0) {
                s--; t--;
                q[x].push_back(x);
            } else {
                q[x].push_back(oc);
            }
            que.push({--k[x], x});
            que.push({k[y], y});
            continue;
        }
        if (s % 2 == 1) {
            s--; t--;
            q[x].push_back(x);
            q[y].push_back(oc);
        } else if (t % 2 == 1) {
            t--;
            q[x].push_back(y);
            q[y].push_back(oc);
        } else if (t > 0 && s > 0) {
            s -= 2; t -= 2;
            q[x].push_back(x);
            q[y].push_back(y);
        } else if (t > 0) {
            t -= 2;
            q[x].push_back(y);
            q[y].push_back(x);
        } else {
            q[x].push_back(oc);
            q[y].push_back(oc);
        }
        que.push({--k[x], x});
        que.push({--k[y], y});
    }
    return s > 0 || t > 0;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); s = read(); t = read();
        _s = s; _t = t;
        for (int c = 0; c <= n; c++) {
            p[c].clear(); q[c].clear();
        }
        for (int i = 0; i < n; i++) {
            a[i] = read(); a[i]--;
            p[a[i]].push_back(i);
        }
        int max = 0, lim;
        for (; !que.empty(); que.pop());
        for (int c = 0; c <= n; c++) {
            k[c] = p[c].size();
            if (k[c] == 0) { oc = c; }
            max = std::max(max, k[c]);
        }
        if (max > n - max) {
            lim = (n - max) * 2;
            for (int c = 0; c <= n; c++) {
                if (k[c] == max) {
                    while (k[c] > n - max) {
                        if (s > 0) {
                            s--; t--;
                            q[c].push_back(c);
                        } else {
                            q[c].push_back(oc);
                        }
                        k[c]--;
                    }
                }
            }
        } else {
            lim = n;
        }
        int sum = 0;
        for (int c = 0; c <= n; c++) {
            que.push({k[c], c});
            sum += k[c];
        }
        if (sum % 2 == 1) {
            while (true) {
                int x = que.top().second; que.pop();
                int y = que.top().second; que.pop();
                if (que.empty()) {
                    que.push({k[x], x});
                    que.push({k[y], y});
                    break;
                }
                int z = que.top().second; que.pop();
                if (k[z] == 0) {
                    que.push({k[x], x});
                    que.push({k[y], y});
                    que.push({k[z], z});
                    break;
                }
                if (s % 2 == 1 && s >= 3) {
                    s -= 3; t -= 3;
                    q[x].push_back(x);
                    q[y].push_back(y);
                    q[z].push_back(z);
                } else if (s % 2 == 1) {
                    s--;
                    if (t >= 3) {
                        t -= 3;
                        q[x].push_back(x);
                        q[y].push_back(z);
                        q[z].push_back(y);
                    } else if (t >= 2) {
                        t -= 2;
                        q[x].push_back(x);
                        q[y].push_back(z);
                        q[z].push_back(oc);
                    } else {
                        t--;
                        q[x].push_back(x);
                        q[y].push_back(oc);
                        q[z].push_back(oc);
                    }
                } else if (t % 2 == 1 && t - 3 >= s) {
                    t -= 3;
                    q[x].push_back(y);
                    q[y].push_back(z);
                    q[z].push_back(x);
                } else if (t % 2 == 1) {
                    t--;
                    q[x].push_back(oc);
                    q[y].push_back(x);
                    q[z].push_back(oc);
                } else if (t > 0 && s > 0) {
                    s -= 2; t -= 2;
                    q[x].push_back(x);
                    q[y].push_back(y);
                    q[z].push_back(oc);
                } else if (t > 0) {
                    t -= 2;
                    q[x].push_back(y);
                    q[y].push_back(x);
                    q[z].push_back(oc);
                } else {
                    q[x].push_back(oc);
                    q[y].push_back(oc);
                    q[z].push_back(oc);
                }
                que.push({--k[x], x});
                que.push({--k[y], y});
                que.push({--k[z], z});
                break;
            }
        }
        while (true) {
            int x = que.top().second; que.pop();
            int y = que.top().second; que.pop();
            if (k[x] == 0 || k[y] == 0) { break; }
            if (s % 2 == 1) {
                s--; t--;
                q[x].push_back(x);
                q[y].push_back(oc);
            } else if (t % 2 == 1) {
                t--;
                q[x].push_back(y);
                q[y].push_back(oc);
            } else if (t > 0 && s > 0) {
                s -= 2; t -= 2;
                q[x].push_back(x);
                q[y].push_back(y);
            } else if (t > 0) {
                t -= 2;
                q[x].push_back(y);
                q[y].push_back(x);
            } else {
                q[x].push_back(oc);
                q[y].push_back(oc);
            }
            que.push({--k[x], x});
            que.push({--k[y], y});
        }
        if ((s > 0 || t > 0) && solveagain()) { printf("NO\n"); continue; }
        printf("YES\n");
        for (int c = 0; c <= n; c++) {
            for (int i = 0; i < q[c].size(); i++) {
                ans[p[c][i]] = q[c][i];
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i] + 1);
        }
        printf("\n");
    }
    return 0;
}