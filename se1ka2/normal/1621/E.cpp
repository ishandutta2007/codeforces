#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Frac
{
    ll p, q;
    
    bool operator<(const Frac &r) const{
        return p * r.q < q * r.p;
    }
    
    bool operator>(const Frac &r) const{
        return p * r.q > q * r.p;
    }
};

Frac a[100005];
int k[100005];
vector<ll> b[100005];
ll s[100005];
int l[100005];
int q[100005];
int h[100005];
pair<Frac, int> p[100005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[i] = Frac{x, 1};
        }
        sort(a, a + n);
        for(int i = 0; i < m; i++){
            b[i].clear();
            cin >> k[i];
            b[i].resize(k[i]);
            s[i] = 0;
            for(int j = 0; j < k[i]; j++){
                cin >> b[i][j];
                s[i] += b[i][j];
            }
        }
        for(int i = 0; i < m; i++) p[i] = pair<Frac, int>(Frac{s[i], k[i]}, i);
        sort(p, p + m);
        vector<int> w;
        vector<int> r;
        for(int i = 0; i < n; i++) h[i] = -1;
        for(int i = 0; i < m; i++) l[i] = -1;
        int j = 0;
        for(int i = 0; i < m; i++){
            q[p[i].second] = i;
            while(j < n){
                if(!(p[i].first > a[j])){
                    l[i] = j;
                    h[j] = i;
                    if(j == 0 || p[i].first > a[j - 1]) w.push_back(i);
                    j++;
                    break;
                }
                else r.push_back(j++);
            }
            if(l[i] == -1){
                if(j > n || p[i].first > a[n - 1]) w.push_back(i);
                else j++;
            }
        }
        while(j < n) r.push_back(j++);
        if(m >= 2 && l[m - 2] == -1){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < k[i]; j++) cout << 0;
            }
            cout << endl;
            continue;
        }
        if(l[m - 1] == -1){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < k[i]; j++){
                    if(w.size() && w.back() > q[i]){
                        cout << 0;
                        continue;
                    }
                    Frac x = Frac{s[i] - b[i][j], k[i] - 1};
                    int u = lower_bound(a, a + n, x) - a;
                    if(r.back() >= u) cout << 1;
                    else cout << 0;
                }
            }
        }
        else{
            for(int i = 0; i < m; i++){
                for(int j = 0; j < k[i]; j++){
                    Frac x = Frac{s[i] - b[i][j], k[i] - 1};
                    int u = lower_bound(a, a + n, x) - a;
                    if((r.size() && r.back() >= u) || l[q[i]] >= u){
                        cout << 1;
                        continue;
                    }
                    if(u == n){
                        cout << 0;
                        continue;
                    }
                    auto itr = upper_bound(w.begin(), w.end(), h[u]);
                    if(itr == w.begin()){
                        cout << 1;
                        continue;
                    }
                    itr--;
                    if(*itr <= q[i]) cout << 1;
                    else cout << 0;
                }
            }
        }
        cout << endl;
    }
}