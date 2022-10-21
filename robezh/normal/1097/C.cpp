#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500;

int n;
string s[N];
int L[N], R[N], M;

int checkL(string &str){
    int l = 0;
    for(int j = 0; j < str.length(); j++){
        if(str[j] == '(') l++;
        else l--;
        if(l < 0) return -1;
    }
    return l;
}

int checkR(string &str){
    int r = 0;
    for(int j = str.length() - 1; j >= 0; j--){
        if(str[j] == ')') r++;
        else r--;
        if(r < 0) return -1;
    }
    return r;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++){
        int l = checkL(s[i]);
        int r = checkR(s[i]);
//        cout << l << ", " << r << endl;
        if(l == 0) assert(r == 0);
        if(l == 0) M ++;
        else if(l > 0) L[l]++;
        else if(r > 0) R[r]++;
    }
    int res = 0;
    for(int i = 0; i < N; i++) res += min(L[i], R[i]);
    res += M / 2;
    M -= M / 2 * 2;
    cout << res << endl;

}