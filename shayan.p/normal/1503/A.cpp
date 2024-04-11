#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(sz(s) & 1 || s[0] == '0'){
        cout << "NO\n";
        return;
    }
    int cnt0 = 0, cnt1 = 0;
    for(char c : s){
        if(c == '0')
            cnt0++;
        else
            cnt1++;
    }
    if(cnt1 & 1){
        cout << "NO\n";
        return;
    }
    string sA = "", sB = "";    
    int used1 = 0;
    int A = 0, B = 0;
    for(char c : s){
        if(c == '0'){
            if(cnt0 & 1){
                sA+= "(";
                sB+= ")";
            }
            else{
                sA+= ")";
                sB+= "(";
            }
            cnt0--;
        }
        else{
            if(used1 + used1 < cnt1){
                sA+= "(";
                sB+= "(";
            }
            else{
                sA+= ")";
                sB+= ")";
            }
            used1++;
        }
        A+= sA.back() == '(' ? 1 : -1;
        B+= sB.back() == '(' ? 1 : -1;
        if(A < 0 || B < 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << sA << "\n" << sB << "\n";
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q;
    cin >> q;
    while(q--){
        solve();
    }
}