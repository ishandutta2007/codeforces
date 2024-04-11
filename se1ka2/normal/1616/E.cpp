#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){   // sum of [0, i)
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
    int q;
    cin >> q;
    while(q--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        queue<int> que[30];
        for(int i = 0; i < n; i++) que[s[i] - 'a'].push(i);
        BIT<int> bit(n);
        for(int i = 0; i < n; i++) bit.add(i, 1);
        ll ans = INF;
        int e = 0;
        ll c = 0;
        for(int i = 0; i < n; i++){
            if(s[e] < t[i]){
                ans = min(ans, c);
                break;
            }
            int k = n;
            for(int j = 0; j < t[i] - 'a'; j++){
                if(que[j].size() && que[j].front() < k) k = que[j].front();
            }
            if(k < n) ans = min(ans, c + bit.sum(k));
            if(k != n && (que[t[i] - 'a'].empty() || k < que[t[i] - 'a'].front())) break;
            if(que[t[i] - 'a'].empty()) break;
            int l = que[t[i] - 'a'].front();
            c += bit.sum(l);
            bit.add(l, -1);
            que[t[i] - 'a'].pop();
            e = n;
            for(int j = 0; j < 26; j++){
                if(que[j].size()) e = min(e, que[j].front());
            }
        }
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}