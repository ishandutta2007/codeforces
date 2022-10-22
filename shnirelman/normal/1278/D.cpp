#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

struct Node {
    int x, y, ind;
    bool fl;

    Node() {};

    Node(int x, int y, int ind, bool fl) : x(x), y(y), ind(ind), fl(fl) {};
};

bool operator < (Node a, Node b) {
    return a.x < b.x;
}

const int N = 5e5 + 13;

int p[N], sz[N];

int getP(int x) {
    if(x == p[x])
        return x;
    return p[x] = getP(p[x]);
}

void unit(int x, int y) {
    x = getP(x);
    y = getP(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    sz[x] += sz[y];
    p[y] = x;
}

void NO() {
    cout << "NO";
    exit(0);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    vector<Node> b(2 * n);
    for(int i = 0; i < n; i++) {
        b[i * 2] = Node(a[i].f, a[i].s, i, false);
        b[i * 2 + 1] = Node(a[i].s, a[i].f, i, true);
    }

    sort(b.begin(), b.end());

    set<Node> s;
    int cnt = 0;
    for(int i = 0; i < 2 * n; i++) {
        //cout << b[i].ind << ' ' << s.size() << endl;
        if(b[i].fl) {
            s.erase(Node(b[i].y, b[i].x, b[i].fl, false));
            //for(auto b1 : s)
            for(auto it = s.end(); it != s.begin(); ) {
                it--;
                Node b1 = *it;
                if(b[i].y < b1.x) {
                    unit(b[i].ind, b1.ind);
                    //cout << b[i].ind << ' ' << b1.ind << endl;
                    cnt++;
                } else
                    break;
            }
        } else {
            s.insert(b[i]);
        }

        //cout << cnt << endl;

        if(cnt > n - 1)
            NO();
    }

    if(cnt < n - 1)
        NO();

        //cout << getP(0) << endl;
    for(int i = 1; i < n; i++) {
       // cout << getP(i) << endl;
        if(getP(i) != getP(i - 1))
            NO();
    }


    cout << "YES";

}