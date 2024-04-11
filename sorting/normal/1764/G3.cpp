#include <iostream>
#include <cassert>
#include <map>
 
using namespace std;
 
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()
 
int n;

map<pair<int, int>, int> mem_q;

int query(int l, int r, int k){
    if(l == r){
        mem_q[{l, r}] = 1;
        return 1;
    }
    cout << "? " << l << " " << r << " " << k << endl;
    int res;
    cin >> res;
    if(k == 2)
        mem_q[{l, r}] = res;
    return res;
}

bool check_for_max(int l, int r){
    if(l == r){
        return query(r + 1, n, n) == 1;
    }
    int q = query(l, r, n);
    return q == 2;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
 
    int mx_idx = -1;
 
    int l = 1, r = n;
    int mid1 = (l + r) >> 1;

    while(r - l > 1){
        int mid = (l + r) >> 1;
        int q1 = query(1, mid, 2);
        int sz1 = mid - 1 + 1;
        int e1 = 2 * q1 - sz1;
 
        int q2 = query(mid + 1, n, 2);
        int sz2 = n - mid;
        int e2 = 2 * q2 - sz2;
 
        if(1 <= mx_idx && mx_idx <= mid)
            --e1;
        if(mid + 1 <= mx_idx && mx_idx <= n)
            --e2;

        if(e1 == e2){
            if(check_for_max(1, mid))
                mx_idx = mid;
            else
                mx_idx = mid + 1;

            if(1 <= mx_idx && mx_idx <= mid)
                --e1;
            if(mid + 1 <= mx_idx && mx_idx <= n)
                --e2;
        }
 
        if(e1 > e2)
            r = mid;
        else
            l = mid + 1;
    }

    if(l == r){
        cout << "! " << l << endl;
        return 0;
    }

    mem_q[{1, 0}] = 0;
    mem_q[{n + 1, n}] = 0;
    mem_q[{1, n}] = n / 2 + 1;

    if(mem_q[{1, l - 1}] + 1 == mem_q[{1, r}]){
        

        int q = query(1, l, 2);
        if(q == mem_q[{1, r}])
            cout << "! " << l << endl;
        else
            cout << "! " << l + 1 << endl;
        return 0;
    }
    if(mem_q[{r + 1, n}] + 1 == mem_q[{l, n}]){
        
        int q = query(r, n, 2);
        if(q == mem_q[{l, n}])
            cout << "! " << r << endl;
        else
            cout << "! " << l << endl;
        return 0; 
    }

    if(check_for_max(1, l))
        cout << "! " << l + 1 << endl;
    else 
        cout << "! " << l << endl; 
}