#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int num[N], a[N];

bool check(int k){
    for(int i = 1; i + k <= n; i++){
        if(a[i] != a[i+k])return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++) a[i] = num[i] - num[i-1];

    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(check(i)) res.push_back(i);
    }
    cout << res.size() << endl;
    for(int x : res) cout << x << " ";
}