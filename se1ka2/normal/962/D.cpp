#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[150004];
    map<ll, set<int>> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].insert(i);
    }
    int ans = n;
    for(auto itr1 = mp.begin(); itr1 != mp.end(); itr1++){
        bool f = false;
        auto litr = itr1->second.begin();
        for(auto itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++){
            if(f){
                a[*itr2] *= 2;
                a[*litr] = -1;
                mp[itr1->first * 2].insert(*itr2);
                ans--;
                f = false;
            }
            else{
                litr = itr2;
                f = true;
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(a[i] != -1) cout << a[i] << " ";
    }
    cout << endl;
}