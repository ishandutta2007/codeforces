#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void dfs(int u, vector<int> &v, ll *a, ll *b){   // a: jun, b : tento
    if(u < 0) return;
    int n = v.size();
    if(n == 0) return;
    ll o = 0, z = 0;
    vector<int> vo, vz;
    for(int i = 0; i < n; i++){
        if((v[i] >> u) & 1){
            o++;
            a[u] += z;
            vo.push_back(v[i]);
        }
        else{
            z++;
            b[u] += o;
            vz.push_back(v[i]);
        }
    }
    dfs(u - 1, vo, a, b);
    dfs(u - 1, vz, a, b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll a[32]{0}, b[32]{0};
    dfs(30, v, a, b);
    ll t = 0;
    int x = 0;
    for(int i = 0; i <= 30; i++){
        if(a[i] < b[i]) x += (1 << i);
        t += min(a[i], b[i]);
    }
    cout << t << " " << x << endl;
}