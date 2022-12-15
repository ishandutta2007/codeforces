#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int a[N];
int x, n;

pair<bool, pair<int, int> > prefix[N], suffix[N];
pair<int, int> p[N];

bool check(int l, int r){
    pair<bool, pair<int, int> > lvalue = prefix[l - 1];
    pair<bool, pair<int, int> > rvalue = suffix[r + 1];

    bool ret = (lvalue.first && rvalue.first);

    if(lvalue.second.second > rvalue.second.first){
        ret = false;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    prefix[0] = {true, {n + 1, -1}};
    suffix[x + 1] = {true, {n + 1, -1}};

    for(int i = 1; i <= x; i++){
        p[i] = {n + 1, -1};
    }

    for(int i = 0; i < n; i++){
        cin >> a[i];

        p[a[i]].first = min(i, p[a[i]].first);
        p[a[i]].second = max(i, p[a[i]].second);
    }

    for(int i = 1; i <= x; i++){
        pair<bool, pair<int, int> > lvalue = prefix[i - 1];
        pair<bool, pair<int, int> > rvalue = {true, p[i]};

        prefix[i].first = (lvalue.first && rvalue.first);

        if(lvalue.second.second > rvalue.second.first){
            prefix[i].first = false;
        }

        prefix[i].second.first = min(lvalue.second.first, rvalue.second.first);
        prefix[i].second.second = max(lvalue.second.second, rvalue.second.second);
    }

    for(int i = x; i >= 1; i--){
        pair<bool, pair<int, int> > rvalue = suffix[i + 1];
        pair<bool, pair<int, int> > lvalue = {true, p[i]};

        suffix[i].first = (lvalue.first && rvalue.first);

        if(lvalue.second.second > rvalue.second.first){
            suffix[i].first = false;
        }

        suffix[i].second.first = min(lvalue.second.first, rvalue.second.first);
        suffix[i].second.second = max(lvalue.second.second, rvalue.second.second);
    }

    /*for(int i = 1; i <= x; i++){
        cout << prefix[i].first << " " << prefix[i].second.first << " " << prefix[i].second.second << " prefix" << endl;
        cout << suffix[i].first << " " << suffix[i].second.first << " " << suffix[i].second.second << " suffix" << endl;
        cout << p[i].first << " p " << p[i].second << endl;
    }*/

    int j = 1;

    long long ans = 0;

    for(int i = 1; i <= x; i++){
        j = max(i, j);

        while(!check(i, j) && j <= x){
            j++;
        }

        //cout << i << " - " << j << endl;

        if(j > x){
            break;
        }

        ans += (long long)(x - j + 1ll);
    }

    cout << ans << "\n";

    return 0;
}