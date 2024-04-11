#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

//istream& operator >>(istream& cin, vector<int>& a) {
//    for(int i = 0; i < a.size(); i++)
//        cin >> a;
//    return cin;
//}

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a != 0)
            s.insert(a);
    }

    cout << s.size();


//    vector<vector<int>> a(n, vector<>)
}