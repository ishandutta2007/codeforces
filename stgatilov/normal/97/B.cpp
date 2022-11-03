#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

struct Point {
        int x, y;

        inline bool operator< (const Point &b) const {
                if (x != b.x) return x < b.x;
                return y < b.y;
        }
};

set<Point> ans;

void Solve(vector<Point> &pts) {
        int n = pts.size();
        if (n == 0) return;
        sort(pts.begin(), pts.end());
        
        int px = pts[n/2].x;
        for (int i = 0; i<n; i++) {
                Point pt;
                pt.x = px;
                pt.y = pts[i].y;
                ans.insert(pt);
        }
        
        vector<Point> left, right;
        for (int i = 0; i<n; i++) {
                if (pts[i].x == px) continue;
                if (pts[i].x < px) left.push_back(pts[i]);
                if (pts[i].x > px) right.push_back(pts[i]);
        }

        Solve(left);
        Solve(right);
}

int n;
vector<Point> pts;

int main() {
#ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif  
        scanf("%d", &n);
        pts.resize(n);
        for (int i = 0; i<n; i++) scanf("%d%d", &pts[i].x, &pts[i].y);

        Solve(pts);

        printf("%d\n", ans.size());
        for (set<Point>::iterator it = ans.begin(); it != ans.end(); it++)
                printf("%d %d\n", it->x, it->y);

        return 0;
}