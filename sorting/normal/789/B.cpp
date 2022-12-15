#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long b, q, l, m;
    cin >> b >> q >> l >> m;

    vector<long long> a(m);
    for(int i = 0; i < m; ++i)
        cin >> a[i];

    set<long long> s;
    for(int i = 0; i < m; ++i)
        s.insert(a[i]);

    long long answer = 0;
    if(q == 0 || b == 0){
        if(abs(b) > l){
            cout << answer << "\n";
            return 0;
        }
        
        if(!s.count(b)){
            ++answer;
        }

        if(!s.count(0)){
            cout << "inf\n";
            return 0;
        }

        cout << answer << "\n";
        return 0;
    }
    if(q == 1){
        if(abs(b) > l){
            cout << "0\n";
            return 0;
        }

        if(s.count(b))
            cout << "0\n";
        else
            cout << "inf\n";
        return 0;
    }
    if(q == -1){
        if(abs(b) > l){
            cout << "0\n";
            return 0;
        }

        if(s.count(b) && s.count(-b))
            cout << "0\n";
        else
            cout << "inf\n";
        return 0;
    }

    while(true){
        if(abs(b) > l)
            break;

        if(!s.count(b))
            ++answer;
        b = b * q;
    }

    cout << answer << "\n";
}