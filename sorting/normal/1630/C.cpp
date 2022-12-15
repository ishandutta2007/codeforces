#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int n, a[N];
pair<int, int> p[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i){
        if(!p[a[i]].first)
            p[a[i]].first = i;
        p[a[i]].second = i;
    }

    vector<pair<int, int>> ranges;
    for(int i = 1; i <= n; ++i){
        if(p[i].first != p[i].second){
            ranges.push_back(p[i]);
        }
    }

    sort(all(ranges));

    vector<pair<int, int>> new_ranges_2;
    int mx = 0;
    for(auto [l, r]: ranges){
        if(mx < r)
            new_ranges_2.push_back({l, r});

        check_max(mx, r);
    }

    vector<pair<int, int>> new_ranges;
    mx = 0;
    pair<int, int> to_push;
    bool anything_to_push = false;
    for(auto [l, r]: new_ranges_2){
        if(mx < l){
            if(anything_to_push){
                new_ranges.push_back(to_push);
                mx = to_push.second;
                anything_to_push = false;
                if(mx > l){
                    to_push = {l, r};
                    anything_to_push = true;
                    continue;
                }
            }
            mx = r;
            new_ranges.push_back({l, r});
        }
        else{
            to_push = {l, r};
            anything_to_push = true;
        }
    }
    if(anything_to_push){
        new_ranges.push_back(to_push);
        anything_to_push = false;
    }

    //for(auto [l, r]: new_ranges)
    //    cout << l << " " << r << " l r" << endl;

    mx = 0;
    int comp = 0, ans = 0;
    pair<int, int> curr_comp{0, 0};
    for(auto [l, r]: new_ranges){
        if(mx < l){
            if(curr_comp.first){
                ans += curr_comp.second - curr_comp.first + 1;
            }
            ++comp;
            curr_comp = {l, r};
        }
        else curr_comp.second = r;
        check_max(mx, r);
    }
    if(curr_comp.first){
        ans += curr_comp.second - curr_comp.first + 1;
    }

    ans -= 2 * new_ranges.size();
    ans += new_ranges.size();
    ans -= comp;

    cout << ans << "\n";
}

/*
6
1 2 3 1 2 3
*/