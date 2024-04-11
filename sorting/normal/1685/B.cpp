#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        string s;
        cin >> s;

        int n = s.size();
        int cnt[2]{};
        for(int i = 0; i < n; ++i)
            cnt[s[i] - 'A']++;

        int exp_cnt[2]{};
        exp_cnt[0] += a;
        exp_cnt[1] += b;
        exp_cnt[0] += c + d;
        exp_cnt[1] += c + d;

        if(exp_cnt[0] != cnt[0] || exp_cnt[1] != cnt[1]){
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> v;
        int start = 0;
        for(int i = 0; i < n; ++i){
            if(i == n - 1 || s[i] == s[i + 1]){
                if(start == i){
                    start = i + 1;
                    continue;
                }
                int len = i - start + 1;
                if(len % 2 == 1)
                    v.push_back({len, 2});
                else{
                    if(s[start] == 'A'){
                        v.push_back({len, 0});
                    }
                    else{
                        v.push_back({len, 1});
                    }
                }
                start = i + 1;
                continue;
            }
        }

        // cout << "v:" << endl;
        multiset<int> ms;
        int mn = 0, mx = 0, sum = 0;
        for(auto [len, type]: v){
            // cout << len << " " << type << " len type" << endl;
            if(type == 2){
                mx += len / 2;
                sum += len / 2;
            }
            else if(type == 0){
                mn += len / 2;
                mx += len / 2;
                sum += len / 2;
            }
            else if(type == 1){
                sum += len / 2;
                ms.insert(len / 2);
            }
        }

        int exp_sum = c + d;
        if(sum < exp_sum){
            cout << "NO\n";
            continue;
        }

        if(mn <= c && c <= mx){
            cout << "YES\n";
            continue;
        }

        if(c < mn){
            mn = 0, mx = 0, sum = 0;
            ms.clear();
            for(auto [len, type]: v){
                if(type == 2){
                    mx += len / 2;
                    sum += len / 2;
                }
                else if(type == 0){
                    sum += len / 2;
                    ms.insert(len / 2);
                }
                else if(type == 1){
                    mn += len / 2;
                    mx += len / 2;
                    sum += len / 2;
                }
            }
            swap(c, d);
        }

        if(c < mn){
            cout << "YES\n";
            continue;
        }

        bool ok = false;
        while(sum >= exp_sum){
            if(mn <= c && c <= mx){
                ok = true;
                break;
            }

            if(ms.empty())
                break;

            int s_mx = *ms.rbegin();
            ms.erase(ms.find(s_mx));

            if(s_mx == 1)
                continue;

            --sum;
            mn += 1;
            mx += s_mx - 1;
        }

        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}