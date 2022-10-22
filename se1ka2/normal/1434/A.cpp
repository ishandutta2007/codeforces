#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int INF = 1000000009;

int main()
{
    int a[6];
    for(int i = 0; i < 6; i++) cin >> a[i];
    int n;
    cin >> n;
    int b[100006];
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        for(int j = 0; j < 6; j++){
            mp[b[i] - a[j]].push_back(i);
        }
    }
    int c = 0;
    int d[100006]{0};
    int ans = INF;
    auto l = mp.begin(), r = mp.begin();
    for(; r != mp.end(); r++){
        for(int i : r->second){
            if(d[i] == 0) c++;
            d[i]++;
        }
        if(c == n){
            while(true){
                ans = min(ans, r->first - l->first);
                for(int i : l->second){
                    d[i]--;
                    if(d[i] == 0) c--;
                }
                l++;
                if(c < n) break;
            }
        }
    }
    cout << ans << endl;
}