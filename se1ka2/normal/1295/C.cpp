#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int w;
    cin >> w;
    for(int c = 0; c < w; c++){
        string s, t;
        cin >> s >> t;
        vector<int> a[26];
        for(int i = 0; i < (int)s.size(); i++){
            a[s[i] - 'a'].push_back(i);
        }
        bool f = true;
        ll ans = 1;
        int k = 0;
        for(int i = 0; i < (int)t.size(); i++){
            if((int)a[t[i] - 'a'].size() == 0){
                f = false;
                break;
            }
            auto itr = lower_bound(a[t[i] - 'a'].begin(), a[t[i] - 'a'].end(), k);
            if(itr == a[t[i] - 'a'].end()){
                ans++;
                k = a[t[i] - 'a'][0] + 1;
            }
            else k = *itr + 1;
        }
        if(!f) cout << -1 << endl;
        else cout << ans << endl;
    }
}