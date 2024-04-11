#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k, x;

// 0 A, 1 C, 2 D

char buf[555];
const long long inf = (1LL << 60);

char solve(int t) {
    if (t == 0)
        return 'A';
    else if (t == 1)
        return 'C';
    else
        return 'D';
}

struct Node {
    int l, r;
    long long num;
    Node(int l, int r, long long num) : l(l), r(r), num(num) {}
    Node() {}
    int ok(int n) {
        
        if (n == 1 && l != r)
            return 0;
        
        buf[1] = solve(l);
        buf[n] = solve(r);
        
        int left = num;
        for(int i = 2; i < n; i++) {
            if (left == 0) {
                buf[i] = 'D';
            } else {
                if (buf[i - 1] == 'A') {
                    buf[i] = 'C';
                    left--;
                } else {
                    buf[i] = 'A';
                }
            }
        }
        if (buf[n] == 'C' && n > 1 && buf[n - 1] == 'A')
            left--;
        buf[n + 1] = 0;
        if (left == 0)
            return 1;
        return 0;
    }
};

Node comb(Node a, Node b) {
    return Node(a.l, b.r, a.num + b.num + (a.r == 0 && b.l == 1));
}

int check(Node a, Node b) {
    Node c;
    for(int i = 3; i <= k; i++) {
        c = comb(a, b);
        a = b;
        b = c;
    }
    if (b.num != x)
        return 0;
    return 1;
}

int main() {
    scanf("%d %d %d %d", &k, &x, &n, &m);
    for(int a1 = 0; a1 < 3; a1++)
        for(int a2 = 0; a2 < 3; a2++)
            for(int aa = 0; aa <= n; aa++)
                for(int b1 = 0; b1 < 3; b1++)
                    for(int b2 = 0; b2 < 3; b2++)
                        for(int bb = 0; bb <= m; bb++) {
                            if (!Node(a1, a2, aa).ok(n) || !Node(b1, b2, bb).ok(m))
                                continue;
                                
                            if (check(Node(a1, a2, aa), Node(b1, b2, bb))) {
                                //printf("%d %d %d\n", a1, a2, aa);
                                //printf("%d %d %d\n", b1, b2, bb);
                                Node(a1, a2, aa).ok(n);
                                puts(buf + 1);
                                
                                Node(b1, b2, bb).ok(m);
                                puts(buf + 1);
                                return 0;
                            }
                        
                        }
    puts("Happy new year!");
    return 0;
}