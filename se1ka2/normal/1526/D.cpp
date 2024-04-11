#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

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

char e[4] = {'A', 'N', 'O', 'T'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int a[100005];
        for(int i = 0; i < n; i++){
            if(s[i] == 'A') a[i] = 0;
            if(s[i] == 'N') a[i] = 1;
            if(s[i] == 'O') a[i] = 2;
            if(s[i] == 'T') a[i] = 3;
        }
        int v[4][100005];
        int c[4]{0};
        for(int i = 0; i < n; i++) v[a[i]][c[a[i]]++] = i;
        int p[4] = {0, 1, 2, 3};
        ll ans = -1;
        string u = "";
        do{
            int b[100005];
            int m = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < c[p[i]]; j++) b[m + j] = p[i];
                m += c[p[i]];
            }
            BIT<ll> bit(n);
            ll s = 0;
            for(int i = 3; i >= 0; i--){
                for(int j = c[p[i]] - 1; j >= 0; j--){
                    s += bit.sum(v[p[i]][j]);
                    bit.add(v[p[i]][j], 1);
                }
            }
            if(s > ans){
                ans = s;
                u = "";
                for(int i = 0; i < n; i++) u += e[b[i]];
            }
        }while(next_permutation(p, p + 4));
        cout << u << "\n";
    }
}