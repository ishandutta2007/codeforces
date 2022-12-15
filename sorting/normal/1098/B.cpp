#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 3;

int n, m;
string s[N];

int ans = N;
string t_ans[N];

string t[N];

void solve(const string &l){
    int cnt;

    cnt = 0;
    for(int i = 0; i < n; ++i){
        int start = (i & 1) << 1;
        int curr1 = 0, curr2 = 0;

        string line1, line2;
        for(int j = 0; j < m; ++j){
            line1.push_back(l[start + (j & 1)]);
            line2.push_back(l[start + 1 - (j & 1)]);
        }

        for(int j = 0; j < m; ++j){
            curr1 += s[i][j] != line1[j];
            curr2 += s[i][j] != line2[j];
        }

        if(curr1 < curr2) t[i] = line1;
        else t[i] = line2;

        cnt += min(curr1, curr2);
    }

    if(cnt < ans){
        for(int i = 0; i < n; ++i)
            t_ans[i] = t[i];
        ans = cnt;
    }

    cnt = 0;
    for(int i = 0; i < m; ++i){
        int start = (i & 1) << 1;
        int curr1 = 0, curr2 = 0;

        string line1, line2;
        for(int j = 0; j < n; ++j){
            line1.push_back(l[start + (j & 1)]);
            line2.push_back(l[start + 1 - (j & 1)]);
        }

        for(int j = 0; j < n; ++j){
            curr1 += s[j][i] != line1[j];
            curr2 += s[j][i] != line2[j];
        }

        if(curr1 < curr2){
            for(int j = 0; j < n; ++j)
                t[j][i] = line1[j];
        }
        else{
            for(int j = 0; j < n; ++j)
                t[j][i] = line2[j];
        }

        cnt += min(curr1, curr2);
    }

    if(cnt < ans){
        for(int i = 0; i < n; ++i)
            t_ans[i] = t[i];
        ans = cnt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    string letters = "ACGT";
    sort(letters.begin(), letters.end());

    do{ solve(letters); }
    while(next_permutation(letters.begin(), letters.end()));

    for(int i = 0; i < n; ++i)
        cout << t_ans[i] << "\n";
}