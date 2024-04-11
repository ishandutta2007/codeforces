#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 300005;
struct Point {
    int x , y;
    Point (int _x = 0 , int _y = 0) {
        x = _x;
        y = _y;
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point& R) const {
        return (LL)x * R.y - (LL)y * R.x;
    }
    LL operator % (const Point& R) const {
        return (LL)x * R.x + (LL)y * R.y;
    }
    bool operator < (const Point &R) const {
        if (x != R.x)
            return x < R.x;
        return y < R.y;
    }
};
int n , m , p;
Point W[N] , K[N];
map<Point , int> Hash;
LL res[N] , ans[N];
int a[N];

bool cmpP(const int &A , const int &B) {
    return W[A] < W[B];
}
bool cmpQ(const int &A , const int &B) {
    return (LL)K[A].x * K[B].y < (LL)K[B].x * K[A].y;
}
void update(vector<int>& P , vector<int>& Q) {
    if (P.empty() || Q.empty())
        return;
    sort(P.begin() , P.end() , cmpP);
    vector<int> A , B;
    for (int i = 0 ; i < Q.size() ; ++ i)
        if (K[Q[i]].y >= 0) {
            A.push_back(Q[i]);
        } else {
            B.push_back(Q[i]);
        }
    sort(A.begin() , A.end() , cmpQ);
    sort(B.begin() , B.end() , cmpQ);
    vector<Point> s(P.size() + 1);
    int t = 0;
    for (int i = 0 ; i < P.size() ; ++ i) {
        Point D = W[P[i]];
        while (t > 1 && ((D - s[t - 2]) ^ (s[t - 1] - s[t - 2])) <= 0)
            -- t;
        s[t ++] = D;
    }
    for (int i = 0 , j = 0 ; i < A.size() ; ++ i) {
        while (j + 1 < t && (K[A[i]] % s[j + 1]) >= (K[A[i]] % s[j]))
            ++ j;
        res[A[i]] = max(res[A[i]] , K[A[i]] % s[j]);
    }

    t = 0;
    for (int i = 0 ; i < P.size() ; ++ i) {
        Point D = W[P[i]];
        while (t > 1 && ((D - s[t - 2]) ^ (s[t - 1] - s[t - 2])) >= 0)
            -- t;
        s[t ++] = D;
    }
    reverse(A.begin() , A.end());
    reverse(B.begin() , B.end());
    for (int i = 0 , j = 0 ; i < B.size() ; ++ i) {
        while (j + 1 < t && (K[B[i]] % s[j + 1]) >= (K[B[i]] % s[j]))
            ++ j;
        res[B[i]] = max(res[B[i]] , K[B[i]] % s[j]);
    }
}
int del[N];
void divide(const vector<int> &A) {
    if (A.size() <= 1)
        return;
    vector<int> P , Q;
    int r = A.size() , mid = r / 2;
    for (int i = 0 ; i < mid ; ++ i)
        P.push_back(A[i]);
    divide(P);
    P.clear();
    for (int i = 0 ; i < r ; ++ i)
        if (A[i] > 0 && (A[i] & 1))
            del[A[i] >> 1] = 1;
    for (int i = 0 ; i < mid ; ++ i)
        if (A[i] > 0 && (~A[i] & 1)) {
            if (!del[A[i] >> 1])
                P.push_back(A[i] >> 1);
            else
                del[A[i] >> 1] = 2;
        }
    for (int i = mid ; i < r ; ++ i)
        if (A[i] < 0)
            Q.push_back(-A[i]);
    update(P , Q);
    Q.clear();
    int c1 = 0 , c2 = 0;
    for (int i = r - 1 ; i >= mid ; -- i) {
        if (A[i] > 0 && (A[i] & 1) && del[A[i] >> 1] == 2) {
            Q.push_back(A[i] ^ 1);
            ++ c1;
        } else if (A[i] < 0) {
            Q.push_back(A[i]);
            ++ c2;
        }
    }
    for (int i = 0 ; i < r ; ++ i)
        if (A[i] > 0 && (A[i] & 1))
            del[A[i] >> 1] = 0;
    if (c1 && c2)
        divide(Q);
    P.clear();
    for (int i = mid ; i < r ; ++ i)
        P.push_back(A[i]);
    divide(P);
}
int iid[N];
void work() {
    scanf("%d" , &n);
    vector<int> A;
    for (int i = 0; i < n ; ++ i) {
        Point S;
        scanf("%d" , &a[i]);
        if (a[i] == 3) {
            scanf("%d" , &S.x);
            S.y = 1;
            ++ m;
            res[m] = -1LL << 60;
            K[m] = S;
            a[i] = -m;
        } else {
            if (a[i] == 1) {
                scanf("%d%d" , &S.x , &S.y);
                W[++ p] = S;
                iid[i] = p;
                //Hash[S] = p;
                a[i] = p << 1;
            } else {
                int j;
                scanf("%d" , &j);
                a[i] = iid[j - 1] << 1 | 1;
                //Hash.erase(S);
            }
        }
        A.push_back(a[i]);
    }
    divide(A);
    for (int i = 1 ; i <= m ; ++ i) {
        if (res[i] == -1LL << 60) {
            puts("EMPTY SET");
        } else {
            printf("%lld\n" , res[i]);
        }
    }
}

int main() {
    work();
    return 0;
}