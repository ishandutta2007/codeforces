#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0;
        for(char c: s)
            if(c == '1')
                ++cnt;

        if((n & 1) || (cnt & 1)){
            cout << "NO\n";
            continue;
        }

        int st[2]{0, 0};
        string ans[2]{"", ""};
        int curr_cnt = 0;
        bool answer = false;
        for(char c: s){
            if(c == '1'){
                if(curr_cnt < cnt / 2){
                    st[0]++;
                    st[1]++;
                    ans[0] += "(";
                    ans[1] += "(";
                }
                else{
                    if(!st[0] || !st[1]){
                        answer = true;
                        cout << "NO\n";
                        break;
                    }
                    --st[0];
                    --st[1];
                    ans[0] += ")";
                    ans[1] += ")";
                }
                ++curr_cnt;
            }
            else{
                if(st[0] > st[1]){
                    swap(st[0], st[1]);
                    swap(ans[0], ans[1]);
                }
                if(!st[1]){
                    answer = true;
                    cout << "NO\n";
                    break;
                }
                st[0]++;
                st[1]--;
                ans[0] += "(";
                ans[1] += ")";
            }
        }

        if(!answer && (st[0] || st[1])){
            answer = true;
            cout << "NO\n";
        }

        if(!answer){
            cout << "YES\n";
            cout << ans[0] << "\n";
            cout << ans[1] << "\n";
        }
    }
}