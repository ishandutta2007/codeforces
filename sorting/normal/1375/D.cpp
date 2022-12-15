#include <bits/stdc++.h>

using namespace std;

const int k_N = 1000 + 3;

int a[k_N];
int cnt[k_N];
int n;

bool check(){
    for(int i = 0; i < n - 1; ++i)
        if(a[i] > a[i + 1])
            return false;
    return true;
}

int get_mex(){
    int mex = 0;
    while(cnt[mex])
        mex++;
    return mex;
}

void solve(){
    vector<int> answer;
    cin >> n;

    for(int i = 0; i <= n; ++i)
        cnt[i] = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    if(check()){
        cout << "0\n\n";
        return;
    }

    while(true){
        //for(int i = 0; i < n; ++i)
        //    cout << a[i] << " ";
        //cout << endl;

        int mex = get_mex();
        if(mex == n){
            for(int i = 0; i < n; ++i)
                if(a[i] != i){
                    cnt[a[i]]--;
                    cnt[mex]++;
                    answer.push_back(i + 1);
                    a[i] = mex;
                    break;
                }
            continue;
        }

        cnt[a[mex]]--;
        cnt[mex]++;
        answer.push_back(mex + 1);
        a[mex] = mex;

        if(check())
            break;
    }

    cout << answer.size() << "\n";
    for(int x: answer)
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