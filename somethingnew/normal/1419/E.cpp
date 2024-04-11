#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
vector<pair<int,int>> div(int n){
    vector<pair<int,int>> res;
    for (int i = 2; i * i <= n; ++i) {
        int step = 0;
        while(n % i == 0){
            n /= i;
            step++;
        }
        if(step)
            res.emplace_back(i, step);
    }
    if(n != 1)
        res.emplace_back(n, 1);
    return res;
}
int pow(int a,int b){
    int res = 1;
    while(b){
        if(b % 2)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
void make(vector<pair<int,int>> &lst, vector<int> &res){
    if(lst.size() == 1){
        int num = 1;
        for (int i = 0; i < lst[0].second; ++i) {
            num *= lst[0].first;
            res.push_back(num);
        }
        return;
    }
    int rr = 1;
    vector<int> rev;
    int goodnum = -1;
    for (int i = 1; i <= lst.back().second; ++i) {
        rr *= lst.back().first;
        int num = rr;
        vector<int> copy(lst.size() - 1, 0);
        while(true){
            if(i == 1){
                if(goodnum == -1 and lst.back().second == 1 and num % lst[lst.size() - 2].first == 0) {
                    goodnum = num;
                }else{
                    rev.push_back(num);
                }
            }else {
                res.push_back(num);
            }
            copy[0]++;
            num *= lst[0].first;
            int q = 0;
            while(q < copy.size() and copy[q] > lst[q].second){
                num /= pow(lst[q].first, copy[q]);
                copy[q] = 0;
                q++;
                if(q == copy.size())
                    break;
                copy[q]++;
                num *= lst[q].first;
            }
            if(q == copy.size())
                break;
        }
        if(i == 1){
            reverse(rev.begin(), rev.end());
            for (auto q : rev)
                res.push_back(q);
            if(lst.back().second == 1)
                res.push_back(goodnum);
        }
    }
   //reverse(rev.begin(), rev.end());
   //for (auto i : rev)
   //    res.push_back(i);
   //if(lst.back().second == 1)
   //    res.push_back(goodnum);
    lst.pop_back();
    make(lst, res);
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> lst = div(n);
    //for (int i = 0; i < lst.size(); ++i) {
    //    cout << lst[i].first << ' ' << lst[i].second << endl;
    //}
    vector<int> ans;
    make(lst, ans);
    for(auto i : ans)
        cout << i << ' ';
    cout << endl;
    int res = 0;
    for (int i = 0; i < ans.size() - 1; ++i) {
        res += (__gcd(ans[i], ans[i+1]) == 1);
    }
    cout << res + (__gcd(ans[0], ans.back()) == 1) << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}