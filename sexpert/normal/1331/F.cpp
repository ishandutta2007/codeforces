#include <bits/stdc++.h>
using namespace std;

set<string> elems = {"H", "HE", "LI", "BE", "B", "C", "N", "O", "F", "NE", "NA", "MG", "AL", "SI", "P", "S", "CL", "AR", "K", "CA", "SC", "TI", "V", "CR", "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS", "SE", "BR", "KR", "RB", "SR", "Y", "ZR", "NB", "MO", "TC", "RU", "RH", "PD", "AG", "CD", "IN", "SN", "SB", "TE", "I", "XE", "CS", "BA", "LA", "CE", "PR", "ND", "PM", "SM", "EU", "GD", "TB", "DY", "HO", "ER", "TM", "YB", "LU", "HF", "TA", "W", "RE", "OS", "IR", "PT", "AU", "HG", "TL", "PB", "BI", "PO", "AT", "RN", "FR", "RA", "AC", "TH", "PA", "U", "NP", "PU", "AM", "CM", "BK", "CF", "ES", "FM", "MD", "NO", "LR", "RF", "DB", "SG", "BH", "HS", "MT", "DS", "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG"};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(elems.count(s.substr(i, 1))) {
            dp[i] |= dp[i + 1];
        }
        if(i < n - 1 && elems.count(s.substr(i, 2))) {
            dp[i] |= dp[i + 2];
        }
    }
    cout << (dp[0] ? "YES" : "NO") << '\n';
}