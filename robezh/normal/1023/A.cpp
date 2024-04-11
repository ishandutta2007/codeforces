#include <bits/stdc++.h>
using namespace std;

int n,m;
string s1, s2;

int main() {
    cin >> n >> m;
    cin >> s1 >> s2;
    if(s1.length() > s2.length() + 1) return !printf("NO");
    int loc = 0;
    while(loc < s1.length() && s1[loc] != '*') loc ++;
    if(loc == s1.length()) return !printf(s1 == s2 ? "YES" : "NO");
    string ls1 = s1.substr(0, loc), ls2 = s2.substr(0, loc);
    //cout << ls1 << " " << ls2 << endl;
    if(ls1 != ls2) return !printf("NO");
    int len = (int)s1.length() - loc - 1;
    string rs1 = s1.substr((int)s1.length()-len), rs2 = s2.substr((int)s2.length()-len);
    //cout << rs1 << " " << rs2 << endl;
    return !printf(rs1 == rs2 ? "YES" : "NO");
}