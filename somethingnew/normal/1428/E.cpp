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
#define int long long
using namespace std;
int f(int x, int k){
    int a2 = x % k;
    int a1 = k - a2;
    return a1 * (x / k) * (x / k) + a2 * (x / k + 1) * (x / k + 1);
}
struct num{
    int x, k;
    int findval(){
        return f(x, k) - f(x, k + 1);
    }
};
bool comp(num a, num b){
    return a.findval() < b.findval();
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<num> lst(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        lst[i].x = a;
        lst[i].k = 1;
        ans += a * a;
    }
    vector<num> heap = lst;
    make_heap(heap.begin(), heap.end(), comp);
    for (int i = 0; i < k - n; ++i) {
        ans -= heap[0].findval();
        pop_heap(heap.begin(), heap.end(), comp);
        heap.back().k++;
        push_heap(heap.begin(), heap.end(), comp);
    }
    cout << ans;
}