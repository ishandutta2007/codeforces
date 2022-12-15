#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> p(n);
    for(int &x: p)
        cin >> x;

    vector<int> v;
    v.push_back(2);
    for(int i = 2; i < n; ++i){
        if((p[i] > p[i - 1]) == (p[i - 1] > p[i - 2]))
            ++v.back();
        else
            v.push_back(2);
    }

    int mx = 0;
    for(int x: v)
        check_max(mx, x);

    if(mx % 2 == 0){
        cout << "0\n";
        return 0;
    }

    vector<int> idx;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == mx)
            idx.push_back(i);

    if(idx.size() == 2 && idx[0] == idx[1] - 1 && (idx[0] % 2 == (p[0] > p[1])))
        cout << "1\n";
    else
        cout << "0\n";
}