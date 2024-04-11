#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <iomanip>
using namespace std;

typedef long long ll;

const long long BIT = 64;
const long double INF = 1e9;
const long double EPS = 1e-12;
const int MSIZE = 200000;
typedef long double ld;
 
struct point {
    long double x, y;
    int id;
    double k;
    point(){}
    point(ld x, ld y): x(x), y(y) {};
};

vector<int> t;
int sz;

void init (int nn){
    sz = nn;
    t.resize(sz, 0);
}

int sum (int r){
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
    	result += t[r];
    return result;
}

void inc (int i, int delta){
    for (; i < sz; i = (i | (i+1)))
	t[i] += delta;
}

int sum (int l, int r){
    return sum (r) - sum (l-1);
}

long long get_inv(vector<int>& v){
    long long res = 0;
    init(v.size());
    for (int i = v.size() - 1; i >= 0; --i){
        res += sum(v[i]);
        inc(v[i], 1);
    }
    return res;
}

bool cmp1(point& p1, point& p2){
    if (abs(p1.y - p2.y) > EPS)
        return p1.y < p2.y;
    else{
        return p1.k > p2.k;
    }
}

bool cmp2(point& p1, point& p2){
    if (abs(p1.y - p2.y) > EPS)
        return p1.y < p2.y;
    else
        return p1.k < p2.k;
}

void solve(){
    ld w;
    int n;
    cin >> n >> w;
    vector<point> ml, mr;
    for (int i = 0; i < n; ++i){
        ld x, v;
        cin >> x >> v;
        ld b = (v / x);
        ld k = 1 / x;
        point res;
        res.id = i;
        res.k = k;
        res.y = b + k * (-w);
        ml.push_back(res);
        res.y = b + k * w;
        mr.push_back(res);
    }
    sort(ml.begin(), ml.end(), cmp1);
    sort(mr.begin(), mr.end(), cmp2);
    vector<int> v1, v2;
    map<int, int> mp;
    for (int i = 0; i < ml.size(); ++i){
        mp[ml[i].id] = i;
        v2.push_back(mr[i].id);
    }
    for (int i = 0; i < v2.size(); ++i)
        v2[i] = mp[v2[i]];
    cout << get_inv(v2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    solve();
    return 0;
}