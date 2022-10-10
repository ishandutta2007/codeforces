#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int ct[26];
vector<int> in;
 
void ans() {
    string s = "";
    if(in.size() >= 4 || in.size() == 1 || (in.size() == 2 && in[1] != in[0] + 1)) {
        for(int i = in.size() - 2; i >= 0; i -= 2) {
            int x = in[i];
            while(ct[x]) {
                ct[x]--;
                s += ('a' + x);
            }
        }
        for(int i = in.size() - 1; i >= 0; i -= 2) {
            int x = in[i];
            while(ct[x]) {
                ct[x]--;
                s += ('a' + x);
            }
        }
    }
    if((in.size() == 2 && in[1] == in[0] + 1) || (in.size() == 3 && in[2] == in[0] + 2)) s = "No answer";
    if(in.size() == 3 && in[2] > in[0] + 2) {
        vector<int> pi;
        if(in[2] != in[1] + 1) pi = {1, 2, 0};
        else pi = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            int x = in[pi[i]];
            while(ct[x]) {
                ct[x]--;
                s += ('a' + x);
            }
        }
    }
    cout << s << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        memset(ct, 0, sizeof ct);
        in.clear();
        for(auto c : s) {
            int x = c - 'a';
            if(!ct[x]) in.push_back(x);
            ct[x]++;
        }
        sort(in.begin(), in.end());
        ans();
    }
}