#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    if(r == 1 && c == 1){
        cout << "0\n";
        return 0;
    }

    vector<int> rows(r), cols(c);
    if(r < c){
        for(int i = 0; i < r; ++i)
            rows[i] = i + 1;
        for(int i = 0; i < c; ++i)
            cols[i] = i + 1 + r;
    }
    else{
        for(int i = 0; i < c; ++i)
            cols[i] = i + 1;
        for(int i = 0; i < r; ++i)
            rows[i] = i + 1 + c;
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cout << rows[i] * cols[j] << " ";
        cout << "\n";
    }
}