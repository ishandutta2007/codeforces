#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

struct vector3
{
    i64 x, y, z;
    vector3() { }
    vector3(i64 x, i64 y, i64 z) : x(x), y(y), z(z) {}

    vector3 sort()
    {
        i64 v[] = { x, y, z };
        std::sort(v, v + 3);
        return vector3(v[0], v[1], v[2]);
    }
};

vector3 operator+(const vector3& a, const vector3& b)
{
    return vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vector3 operator-(const vector3& a, const vector3& b)
{
    return vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

i64 operator*(const vector3& a, const vector3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline bool operator<(const vector3& a, const vector3& b)
{
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    if (a.y < b.y) return true;
    if (a.y > b.y) return false;
    return a.z < b.z;
}

inline bool operator==(const vector3& a, const vector3& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool used[8];

vector3 pts[8];

vector3 vec[3];
vector3 sol[8];

bool check()
{
    if (vec[0] * vec[1] != 0) return false;
    if (vec[0] * vec[2] != 0) return false;
    if (vec[2] * vec[1] != 0) return false;
    i64 norm = vec[0] * vec[0];
    if (norm == 0) return false;
    if (norm != vec[1] * vec[1]) return false;
    if (norm != vec[2] * vec[2]) return false;

    vector<vector3> rems;
    for (int i = 1; i < 8; ++i) if (!used[i]) rems.push_back(pts[i]);

    vector<pair<vector3, vector3> > reqs;

    vector3 bas;
    bas = vec[0] + vec[1] + pts[0];
    reqs.push_back(make_pair(bas.sort(), bas));
    bas = vec[0] + vec[2] + pts[0];
    reqs.push_back(make_pair(bas.sort(), bas));
    bas = vec[2] + vec[1] + pts[0];
    reqs.push_back(make_pair(bas.sort(), bas));
    bas = vec[0] + vec[1] + vec[2] + pts[0];
    reqs.push_back(make_pair(bas.sort(), bas));

    for (int i = 1; i < 8; ++i) if (!used[i]) {
        for (int j = 0; j < reqs.size(); ++j) {
            if (reqs[j].first == pts[i]) {
                sol[i] = reqs[j].second;
                reqs.erase(reqs.begin() + j);
                break;
            }
        }
    }

    if (reqs.size() == 0){
        puts("YES");
        for (int i = 0; i < 8; ++i) printf("%d %d %d\n", (int)sol[i].x, (int)sol[i].y, (int)sol[i].z);
        return true;
    }
    return false;
}

bool dfs(int p)
{
    if (p == 3) {
        if (check()) return true;
        return false;
    } else {
        for (int i = 1; i < 8; ++i) {
            if (used[i]) continue;
            used[i] = true;

            vector3& bas = pts[i];
            sol[i] = (vec[p] = vector3(bas.x, bas.y, bas.z) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;
            sol[i] = (vec[p] = vector3(bas.x, bas.z, bas.y) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;
            sol[i] = (vec[p] = vector3(bas.y, bas.x, bas.z) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;
            sol[i] = (vec[p] = vector3(bas.y, bas.z, bas.x) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;
            sol[i] = (vec[p] = vector3(bas.z, bas.x, bas.y) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;
            sol[i] = (vec[p] = vector3(bas.z, bas.y, bas.x) - pts[0]) + pts[0];
            if (dfs(p + 1)) return true;

            used[i] = false;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 8; ++i) {
        int x[3];
        scanf("%d%d%d", x, x + 1, x + 2);
        sort(x, x + 3);

        pts[i] = vector3(x[0], x[1], x[2]);
    }

    for (int i = 0; i < 8; ++i) used[i] = false;

    sol[0] = pts[0];
    if (!dfs(0)) puts("NO");

    return 0;
}