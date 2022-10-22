#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int s[100005];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = n - 1; i >= 0; i--){
        if(s[i] > 1){
            cout << -1 << endl;
            return 0;
        }
        if(s[i] == 1) break;
    }
    vector<P> ans;
    int h = 0;
    int l = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 3){
            if(h) ans.push_back(P(h - 1, i));
            ans.push_back(P(h, i));
            h++;
            l = i;
        }
    }
    bool f = false;
    if(h == 0) f = true;
    if(!f){
        for(int i = l; i < n; i++){
            if(s[i] == 2){
                ans.push_back(P(h - 1, i));
                f = true;
                break;
            }
        }
    }
    if(!f){
        for(; l < n; l++){
            if(s[l] == 1){
                ans.push_back(P(h - 1, l));
                ans.push_back(P(h, l));
                break;
            }
        }
    }
    int one = 0, two = 0;
    for(int i = n - 1; i >= 0; i--){
        if(!f && i == l) continue;
        if(s[i] == 1){
            ans.push_back(P(n - 1 - one, i));
            one++;
        }
        if(s[i] == 2){
            if(two >= one){
                cout << -1 << endl;
                return 0;
            }
            ans.push_back(P(n - 1 - two, i));
            two++;
        }
    }
    cout << (int)ans.size() << endl;
    for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
}