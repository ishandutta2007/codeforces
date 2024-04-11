#include <iostream>
 
using namespace std;
 
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()
 
int n;

int query(int l, int r, int k){
    cout << "? " << l << " " << r << " " << k << endl;
    int res;
    cin >> res;
    return res;
}

bool check_for_max(int l, int r){
    int q = query(l, r, n);
    return q == 2 || (q == 1 && r == l);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
 
    int mx_idx = -1;
 
    int l = 1, r = n;
    while(l != r){
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
 
    cout << "! " << l << endl; 
}