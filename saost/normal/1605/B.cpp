#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
vector<int> Ans, Ans2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        Ans.clear(); Ans2.clear();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j && s[i] == '0') ++i;
            while (i <= j && s[j] == '1') --j;
            if (i <= j) {
                Ans.push_back(i++);
                Ans2.push_back(j--);
            }
        }
        if (Ans.size()) {
            cout << "1\n" << Ans.size()*2 << '\n';
            for(int v : Ans) cout << v + 1 << ' ';
            for(int i=Ans2.size()-1; i>=0; --i) cout << Ans2[i] + 1 << ' ';
            cout << '\n';
        }
        else cout << "0\n";
    }
}