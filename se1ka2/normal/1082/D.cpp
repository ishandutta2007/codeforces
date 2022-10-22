#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[502];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 2;
    }
    int f = n, l = -1;
    vector<P> ans;
    int d = -1;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            f = min(f, i);
            l = max(l, i);
            for(int j = i + 1; j < n; j++){
                if(a[j] >= 0){
                    ans.push_back(P(i, j));
                    break;
                }
            }
            d++;
        }
    }
    if(l == -1){
        cout << "NO" << endl;
        return 0;
    }
    bool w = false, v = false;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            if(!w){
                ans.push_back(P(f, i));
                w = true;
                d++;
            }
            else if(!v){
                ans.push_back(P(l, i));
                v = true;
                d++;
            }
            else{
                for(int j = 0; j < n; j++){
                    if(a[j] > 0){
                        ans.push_back(P(j, i));
                        a[j]--;
                        break;
                    }
                }
            }
        }
    }
    if((int)ans.size() < n - 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES " << d << endl;
        cout << (int)ans.size() << endl;
        for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}