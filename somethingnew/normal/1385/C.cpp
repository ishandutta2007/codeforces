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

using namespace std;

bool good(list<int> a){
    int min = 0;
    while(!a.empty()){
        if(a.back() < a.front()){
            if(a.back() < min) return false;
            min = a.back();
            a.pop_back();
        } else{
            if(a.front() < min) return false;
            min = a.front();
            a.pop_front();
        }
    }
    return true;
}

bool test(int pos, vector<int> lst){
    list<int> b;
    for (int i = pos; i < lst.size(); ++i) {
        b.push_back(lst[i]);
    }
    return good(b);
}

void solve(){
    int n;
    cin >> n;
    vector<int> q;
    for (int i = 0; i < n; ++i) {
        int a;cin >> a;
        q.push_back(a);
    }
    int l = -1, r = n;
    while(r-l>1){
        int m = (l+r)/2;
        if(test(m,q)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}