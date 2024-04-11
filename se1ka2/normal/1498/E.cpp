#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int main()
{
    int n;
    cin >> n;
    int k[502];
    for(int i = 0; i < n; i++) cin >> k[i];
    PP p[250002];
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            p[c++] = PP(abs(k[i] - k[j]), P(i, j));
        }
    }
    sort(p, p + c, greater<PP>());
    for(int i = 0; i < c; i++){
        int a = p[i].second.first, b = p[i].second.second;
        if(k[a] < k[b]) swap(a, b);
        cout << "? " << a + 1 << " " << b + 1 << endl;
        string s;
        cin >> s;
        if(s == "Yes"){
            cout << "! " << a + 1 << " " << b + 1 << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
}