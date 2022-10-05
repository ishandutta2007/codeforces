#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
struct vertex {
    int open = 0, close = 0, clr = -1, blclr = -1;
};
vertex merge(vertex left, vertex right) {
    vertex ans = right;
    if (ans.open + ans.close == 0)
        ans = left;
    if (left.open) {
        if (right.clr != -1 or right.blclr != -1) {
            ans.blclr = right.blclr;
            if (ans.blclr == -1)
                ans.blclr = right.clr;
        } else {
            ans.clr = left.clr;
            ans.blclr = left.blclr;
        }
    } else if (left.close) {
        ans.clr = left.clr;
        ans.blclr = right.blclr;
        if (ans.blclr == -1)
            ans.blclr = left.blclr;
    } else {
        ans.clr = right.clr;
        if (ans.clr == -1)
            ans.clr = left.clr;
        ans.blclr = right.blclr;
        if (ans.blclr == -1)
            ans.blclr = left.blclr;
    }
    return ans;
}
struct segtree{
    int sz;
    vector<vertex> tree;
    void make(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
    }
    void change(int v, int op, int num = -1) {
        v += sz;
        if (op == 1) { // open
            tree[v] = {1, 0, -1, -1};
        }
        if (op == 2) { // close
            tree[v] = {0, 1, -1, -1};
        }
        if (op == 3) { // color
            tree[v] = {0, 0, num, -1};
        }
        while (v != 1) {
            v /= 2;
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    int get() {
        int v = tree[1].blclr;
        if (v == -1)
            v = tree[1].clr;
        if (v == -1)
            v = 4;
        return v;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string, int> mp1;
    mp1["red"] = 0;
    mp1["orange"] = 1;
    mp1["yellow"] = 2;
    mp1["green"] = 3;
    mp1["blue"] = 4;
    mp1["indigo"] = 5;
    mp1["violet"] = 6;
    map<int, string> mp2;
    for (auto [key, val] : mp1)
        mp2[val] = key;
    segtree sg;
    sg.make(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "lock")
            sg.change(i, 2);
        else if (s == "unlock")
            sg.change(i, 1);
        else
            sg.change(i, 3, mp1[s]);
    }
    int t = 0;
    cout << mp2[sg.get()] << '\n';;
    for (int i = 0; i < t; ++i) {
        int a;
        string s;
        cin >> a >> s;
        a--;
        if (s == "lock")
            sg.change(a, 2);
        else if (s == "unlock")
            sg.change(a, 1);
        else
            sg.change(a, 3, mp1[s]);
        cout << mp2[sg.get()] << '\n';
    }
}