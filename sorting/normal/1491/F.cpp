#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 3;

int n;

void answer(vector<int> ans){
    cout << "! " << ans.size() << " ";
    for(int x: ans)
        cout << x << " ";
    cout << "\n";
    cout.flush();
}

int query(vector<int> l, vector<int> r){
    cout << "? " << l.size() << " " << r.size() << "\n";
    cout.flush();

    for(int x: l)
        cout << x << " ";
    cout << "\n";
    cout.flush();
    for(int x: r)
        cout << x << " ";
    cout << "\n";
    cout.flush();

    int ans;
    cin >> ans;
    return ans; 
}

vector<int> get_range(int l, int r){
    vector<int> v;
    for(int i = l; i <= r; ++i)
        v.push_back(i);
    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 2; i <= n; ++i){
            int x = query(get_range(1, i - 1), {i});
            if(x){
                vector<int> ans;
                int l = 1, r = i - 1;
                while(l != r){
                    int mid = (l + r) >> 1;
                    if(query(get_range(1, mid), {i})) r = mid;
                    else l = mid + 1;
                }

                for(int j = 1; j < l; ++j)
                    ans.push_back(j);
                for(int j = l + 1; j < i; ++j)
                    ans.push_back(j);
                for(int j = i + 1; j <= n; ++j)
                    if(!query({j}, {i}))
                        ans.push_back(j);
                answer(ans);
                break;
            }
        }
    }
}