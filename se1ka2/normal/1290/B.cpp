#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

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
    string s;
    cin >> s;
    int n = s.size();
    vector<BIT<int>> bit(26, BIT<int>(n));
    for(int i = 0; i < n; i++){
        bit[s[i] - 'a'].add(i, 1);
    }
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(l == r || s[l] != s[r]){
            cout << "Yes" << endl;
            continue;
        }
        int k = bit[s[r] - 'a'].sum(r) - bit[s[r] - 'a'].sum(l - 1);
        if(k == r - l + 1){
            cout << "No" << endl;
            continue;
        }
        for(int i = 0; i < 26; i++){
            if(s[r] - 'a' == i) continue;
            int h = bit[i].sum(r) - bit[i].sum(l - 1);
            if(h){
                if(k + h == r - l + 1) cout << "No" << endl;
                else cout << "Yes" << endl;
                break;
            }
        }
    }
}