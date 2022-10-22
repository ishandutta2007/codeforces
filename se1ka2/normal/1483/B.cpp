#include <iostream>
#include <vector>
using namespace std;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int right[100005];
        vector<int> ans;
        vector<int> last;
        bool b[100005];
        for(int i = 0; i < n; i++){
            last.push_back(i);
            right[i] = (i + 1) % n;
            b[i] = true;
        }
        while(last.size()){
            vector<int> next;
            for(int i : last){
                if(!b[i]) continue;
                if(gcd(a[i], a[right[i]]) == 1){
                    b[right[i]] = false;
                    next.push_back(i);
                    ans.push_back(right[i]);
                    right[i] = right[right[i]];
                }
            }
            swap(last, next);
        }
        cout << (int)ans.size() << " ";
        for(int b : ans) cout << b + 1 << " ";
        cout << endl;
    }
}