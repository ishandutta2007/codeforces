#include <iostream>
#include <vector>
using namespace std;

int a[1000002], b[1000002], c[1000002];
int ans[1000002];

int main()
{
    int n;
    cin >> n;
    int k = 0;
    int d = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] > 0){
            if(c[a[i]] == 1 || b[a[i]] == 1){
                cout << -1 << endl;
                return 0;
            }
            v.push_back(a[i]);
            c[a[i]]++;
            b[a[i]]++;
            k++;
        }
        else{
            if(b[-a[i]] == 0){
                cout << -1 << endl;
                return 0;
            }
            b[-a[i]]--;
            k--;
        }
        if(k == 0){
            ans[d] = i + 1;
            d++;
            for(int x : v) c[x] = 0;
            v.clear();
        }
    }
    if(k != 0){
        cout << -1 << endl;
        return 0;
    }
    cout << d << endl;
    cout << ans[0] << " ";
    for(int i = 1; i < d; i++) cout << ans[i] - ans[i - 1] << " ";
    cout << endl;
}