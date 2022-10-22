#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    int b[200005] {0};
    P pa[200005];
    vector<int> v;
    for(int i = 0; i < q; i++){
        int r;
        cin >> r;
        if(r == 1){
            int p, x;
            cin >> p >> x;
            p--;
            pa[i] = P(p, x);
        }
        else{
            int x;
            cin >> x;
            pa[i] = P(-1, -1);
            b[i] = x;
            v.push_back(i);
        }
    }
    v.push_back(q);
    for(int i = q - 1; i >= 0; i--){
        b[i] = max(b[i], b[i + 1]);
    }
    for(int i = 0; i < n; i++) a[i] = max(a[i], b[0]);
    for(int i = 0; i < q; i++){
        if(pa[i].first == -1) continue;
        a[pa[i].first] = max(pa[i].second, b[*lower_bound(v.begin(), v.end(), i)]);
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}