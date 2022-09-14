#include<bits/stdc++.h>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    vector<long long> a(k + 1), b(n);
    set<long long> s;
    for(int i = 0; i < k; i++){
        cin >> a[i + 1];
        a[i + 1] += a[i];
        s.insert(a[i + 1]);
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    set<long long> ans;
    for(int i = 0; i < k; i++){
        long long c = b[0] - a[i + 1];
        int l = 0;
        bool flag = 1;
        for(int j = 0; j < n; j++){
            if(s.find(b[j] - c) == s.end()){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans.insert(c);
        }
    }
    cout << ans.size();
}