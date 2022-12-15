#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

int l, r;
bool f_all;

char get(int idx){
    if(f_all)
        return ('1' - a[r - idx]) + '0';
    else
        return a[l + idx];
}

void solve(){
    cin >> n;
    cin >> a >> b;

    vector<int> p;
    l = 0, r = n - 1;
    f_all = false;

    for(int i = n - 1; i >= 0; --i){
        if(get(i) == b[i]){
            if(f_all) l++;
            else r--;
            continue;
        }
    
        if(get(0) != get(i)){
            //do_operation(0);
            p.push_back(0);
        }

        f_all ^= true;
        p.push_back(i);

        if(f_all) l++;
        else r--;
    }

    cout << p.size() << " ";
    for(int x: p)
        cout << x + 1 << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}