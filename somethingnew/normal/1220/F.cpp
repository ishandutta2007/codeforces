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
struct node{
    int num = 1;
    int left = 0, right = 0;
    node * batya = nullptr;
    int upsize = 0;
    int mx() {
        return max(left, right);
    }
};
vector<int> findres(vector<int> nums) {
    node * root = new node;
    node * vetka = root;
    int res = 1;
    vector<int> ans = {res};
    for (auto i : nums) {
        int glub = 0;
        while (i < vetka->num) {
            glub = max(glub, vetka->left);
            glub++;
            vetka = vetka->batya;
        }
        node * b = new node;
        b->num = i;
        b->batya = vetka;
        b->upsize = vetka->upsize + 1;
        b->left = glub;
        vetka = b;
        res = max(res, vetka->upsize + vetka->mx() + 1);
        ans.push_back(res);
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> left, right;
    vector<int> res1(n), res2(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            for (int j = 1; j < n; ++j) {
                left.push_back(a[(i + n - j) % n]);
                right.push_back(a[(i + j) % n]);
            }
            vector<int> l1 = findres(left), r1 = findres(right);
            for (int j = 0; j < n; ++j) {
                res2[(n - 1 - i - j + n) % n] = r1[j];
                res1[(n - i + j) % n] = l1[j];
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << res1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << res2[i] << ' ';
    }*/
    int v = 0;
    for (int i = 0; i < n; ++i) {
        if (max(res1[i], res2[i]) < max(res1[v], res2[v])) {
            v = i;
        }
    }
    cout << max(res1[v], res2[v]) << ' ' << (n - v) % n << endl;
}