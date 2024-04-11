#include <bits/stdc++.h>

using namespace std;

const int N = 2021 + 3;

int n, a[N];
vector<int> ans;

void do_rev(int x){
    ans.push_back(x);
    reverse(a + 1, a + x + 1);
}

void solve(){
    ans.clear();

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        if((i & 1) != (a[i] & 1)){
            cout << "-1\n";
            return;
        }

    for(int i = n; i > 1; i -= 2){
        int x, y;
        for(int j = 1; j <= n; ++j){
            if(a[j] == i) x = j;
            if(a[j] == i - 1) y = j; 
        }

        if(x < y){
            do_rev(x);
            do_rev(y - 1);
            do_rev(y + 1);
            do_rev(3);
            do_rev(i);
        }
        else{
            do_rev(x);
            do_rev(x - y);
            do_rev(x - y + 2);
            do_rev(3);
            do_rev(i);
        }
    }

    cout << ans.size() << "\n";
    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}