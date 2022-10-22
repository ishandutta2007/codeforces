#include <iostream>
#include <string>
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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v[30];
    for(int i = 0; i < n; i++){
        v[s[i] - 'a'].push_back(i);
    }
    vector<int> r[30];
    for(int j = 0; j < 26; j++){
        r[j].resize((int)v[j].size());
        for(int i = 0; i < (int)v[j].size(); i++){
            r[j][i] = n - 1 - v[j][(int)v[j].size() - 1 - i];
        }
    }
    BIT<ll> bit(n);
    ll ans = 0;
    int d[30]{0};
    for(int i = 0; i < n; i++){
        int j = s[i] - 'a';
        ans += (i - bit.sum(r[j][d[j]]));
        bit.add(r[j][d[j]], 1);
        d[j]++;
    }
    cout << ans << endl;
}