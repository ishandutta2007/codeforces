#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p,k;
vector<int> res;

int main(){
    cin >> p >> k;
    bool po = true;
    while(p > 0){
        ll rem = p % k;
        if(po) res.push_back(rem), p -= rem;
        else {
            if (rem == 0) res.push_back(0);
            else res.push_back(k - rem), p += (k - rem);
        }
        p /= k;
        po = !po;
    }
    cout << res.size() << endl;
    for(int r : res) cout << r << " ";
}