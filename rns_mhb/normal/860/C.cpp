#include<bits/stdc++.h>
using namespace std;

int main() {
    auto trans = [&](int x) {
        string r = "";
        while(x) r += '0'+x%10, x/=10;
        reverse(r.begin(), r.end());
        return r;
    };
    set <string> A, B, C, D;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        string s, p;
        cin >> s >> p;
        if(p == "1") A.insert(s);
        else B.insert(s);
    }
    for(int i = 1; i <= A.size(); i ++) C.insert(trans(i));
    for(int i = 1; i <= B.size(); i ++) D.insert(trans(A.size()+i));
    vector <string> u, v;
    for(auto s : A) if(C.count(s)) u.push_back(s);
    for(auto s : u) A.erase(s), C.erase(s);
    for(auto s : B) if(D.count(s)) v.push_back(s);
    for(auto s : v) B.erase(s), D.erase(s);
    set <string> gA, bA, gB, bB, gC, bC, gD, bD;
    for(auto s : A) {
        if(D.count(s)) bA.insert(s);
        else gA.insert(s);
    }
    for(auto s : D) {
        if(A.count(s)) bD.insert(s);
        else gD.insert(s);
    }
    for(auto s : B) {
        if(C.count(s)) bB.insert(s);
        else gB.insert(s);
    }
    for(auto s : C) {
        if(B.count(s)) bC.insert(s);
        else gC.insert(s);
    }
    vector <pair<string, string> > ans;
    while(bA.size() + gA.size() + bB.size() + gB.size() > 0) {
        if(!bA.empty() && !gC.empty()) {
            string x = *bA.begin(), y = *gC.begin();
            ans.push_back(make_pair(x, y));
            bA.erase(x), bD.erase(x), gD.insert(x), gC.erase(y);
            continue;
        }
        if(!bB.empty() && !gD.empty()) {
            string x = *bB.begin(), y = *gD.begin();
            ans.push_back(make_pair(x, y));
            bB.erase(x), bC.erase(x), gC.insert(x), gD.erase(y);
            continue;
        }
        if(bA.empty() && bB.empty()) {
            if(!gA.empty()) {
                string x = *gA.begin(), y = *gC.begin();
                ans.push_back(make_pair(x, y));
                gA.erase(x), gC.erase(y);
                continue;
            }
            if(!gB.empty()) {
                string x = *gB.begin(), y = *gD.begin();
                ans.push_back(make_pair(x, y));
                gB.erase(x), gD.erase(y);
                continue;
            }
        }
        string y = trans(++ n);
        string x = *bA.begin();
        ans.push_back(make_pair(x, y));
        bA.erase(x);
        gA.insert(y);
        bD.erase(x), gD.insert(x);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++) cout << "move " << ans[i].first << ' ' << ans[i].second << endl;
}