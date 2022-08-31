#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n;
int a[SZ];
vector<int> ans;

bool solve() {
    int start = 0;
    int inside = 0;
    set<int> enter, exit;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (enter.count(a[i])) {
                // entered already before, so new day?
                if (inside != 0)
                    return false;
                ans.push_back(i - start);
                inside = 0;
                enter.clear();
                exit.clear();
            }
            enter.insert(a[i]);
            inside++;
            if (inside == 1)
                start = i;
        } else {
            if (!enter.count(-a[i])) {
                // how did they even enter?
                return false;
            }
            if (exit.count(-a[i])) {
                // exit again? 
                return false;
            }
            exit.insert(-a[i]);
            inside--;

            if (inside == 0) {
                ans.push_back(i - start + 1);
                inside = 0;
                enter.clear();
                exit.clear();
            }
        }
    }

    return inside == 0;
}

int main() {
    setIO();
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    ans.clear();

    if (solve()) {
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    } else {
        cout<<"-1"<<endl;
    }
    
    return 0;
}