#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

string s;
int cnt[26];

void solve(){
    cin >> s;
    fill(cnt, cnt + 26, 0);
    for(char c: s)
        cnt[c - 'a']++;

    for(int i = 0; i < 26; ++i)
        if(cnt[i] == 1){
            cout << (char)(i + 'a');
            --cnt[i];
            for(int j = 0; j < 26; ++j)
                for(int k = 0; k < cnt[j]; ++k)
                    cout << (char)(j + 'a');
            cout << "\n";
            return;
        }

    int first = -1, second = -1;
    for(int i = 0; i < 26; ++i)
        if(cnt[i]){
            if(first == -1){
                first = i;
            }
            else if(second == -1){
                second = i;
            }
        }

    if(second == -1){
        cout << s << "\n";
        return;
    }
    if(cnt[first] <= (int)s.size() / 2 + 1){
        cout << (char)(first + 'a');
        cnt[first]--;
        for(int i = 0; i < (int)s.size() - 1; ++i){
            if(i % 2 == 0){
                for(int j = 0; j < 26; ++j)
                    if(cnt[j]){
                        cout << (char)(j + 'a');
                        --cnt[j];
                        break;
                    }
            }
            else{
               for(int j = first + 1; j < 26; ++j)
                    if(cnt[j]){
                        cout << (char)(j + 'a');
                        --cnt[j];
                        break;
                    } 
            }
        }
        cout << "\n";
        return;
    }

    cout << (char)(first + 'a');
    cnt[first]--;
    cout << (char)(second + 'a');
    cnt[second]--;

    for(int i = 0; i < (int)s.size() - 2; ++i){
        if(cnt[first]){
            if(!cnt[second]){
                cout << (char)(first + 'a');
                --cnt[first];
                continue;
            }
            if(cnt[first] + cnt[second] != (int)s.size() - 2 - i){
                while(cnt[first]){
                    cout << (char)(first + 'a');
                    --cnt[first];
                }
                for(int j = 0; j < 26; ++j)
                    if(cnt[j] && j != second){
                        cout << (char)(j + 'a');
                        --cnt[j];
                        break; 
                    }
                continue;
            }
            else{
                while(cnt[second]){
                    cout << (char)(second + 'a');
                    --cnt[second];
                }
                while(cnt[first]){
                    cout << (char)(first + 'a');
                    --cnt[first];
                }
            }
        }
        break;
    }
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < cnt[i]; ++j)
            cout << (char)(i + 'a');
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}