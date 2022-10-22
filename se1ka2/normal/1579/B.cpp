#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

void shift(int l, int r, int *a){
    int t = a[l];
    for(int i = l; i < r - 1; i++) a[i] = a[i + 1];
    a[r - 1] = t;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[52];
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<P> ans;
        for(int i = n - 1; i >= 0; i--){
            int l = i;
            for(int j = i - 1; j >= 0; j--){
                if(a[j] > a[l]) l = j;
            }
            if(l < i){
                shift(l, i + 1, a);
                ans.push_back(P(l, i));
            }
        }
        cout << ans.size() << endl;
        for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << " " << 1 << endl;
    }
}