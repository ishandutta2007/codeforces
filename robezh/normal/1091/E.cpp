#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500;

int n;
int a[N], odd;
ll ssum[N];
ll psum[N];

int check(int d){
    int put = -1;
    vector<int> deg;
    deg.clear();
    deg.push_back(0);
    for(int i = 0; i < n; i++){
        if(a[i] < d && put == -1){
            put = deg.size();
            deg.push_back(d);
        }
        deg.push_back(a[i]);
    }
    if(put == -1) put = deg.size(), deg.push_back(d);

    int n1 = deg.size() - 1;
    ssum[n1 + 1] = 0;
    for(int i = n1; i >= 1; i--) ssum[i] = ssum[i+1] + deg[i];
    psum[0] = 0;
    for(int i = 1; i <= n1; i++) psum[i] = psum[i-1] + deg[i];
    int pt = n1 + 1;
    for(int k = 1; k <= n1; k++){
        while(pt - 1 >= 1 && deg[pt-1] < k) pt--;
        ll LHS = psum[k];
        ll RHS = 1LL * k * (k - 1);
        if(pt >= k + 1) RHS += 1LL * k * (pt - (k + 1)) + ssum[pt];
        else RHS += ssum[k+1];
        if(LHS > RHS){
            if(put <= k) return 1;
            else return -1;
        }
    }
    return 0;
}

int get(int type){
    int l = -1, r = (n + 2) / 2, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        int d = mid * 2 + odd;
        if(check(d) >= type) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    odd = int(sum % 2);

    int lb = get(0), rb = get(1);
    if(lb >= rb) printf("-1");
    else for(int i = lb; i < rb; i++) printf("%d ", i * 2 + odd);
}