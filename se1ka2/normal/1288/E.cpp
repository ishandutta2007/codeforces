#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[300005];
int last[300005];
int ans[300005];

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    fill(last, last + n, -1);
    BIT<int> fir(n);
    BIT<int> dub(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
        if(last[a[i]] == -1){
            ans[a[i]] = a[i] + (fir.sum(n - 1) - fir.sum(a[i])) + 1;
            fir.add(a[i], 1);
        }
        else{
            ans[a[i]] = max(ans[a[i]], i - last[a[i]] - (dub.sum(i - 1) - dub.sum(last[a[i]])));
            dub.add(last[a[i]], 1);
        }
        last[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(last[i] != -1) cout << 1 << " ";
        else cout << i + 1 << " ";
        if(last[i] == -1) ans[i] = i + (fir.sum(n - 1) - fir.sum(i)) + 1;
        else ans[i] = max(ans[i], m - last[i] - (dub.sum(m - 1) - dub.sum(last[i])));
        cout << ans[i] << endl;
    }
}