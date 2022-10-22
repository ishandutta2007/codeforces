#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    ll x[200005];
    vector<int> v[200005];
    for(int i = 0; i < m; i++){
        cin >> x[i];
        x[i]--;
        v[x[i]].push_back(i);
    }
    ll s = 0;
    for(int i = 1; i < m; i++) s += abs(x[i] - x[i - 1]);
    cout << s << " ";
    for(int i = 1; i < n; i++){
        ll sub = 0;
        for(int j : v[i - 1]){
            if(j != 0) sub += abs(x[j] - x[j - 1]);
            if(j != m - 1) sub += abs(x[j + 1] - x[j]);
        }
        for(int j : v[i]){
            if(j != 0) sub += abs(x[j] - x[j - 1]);
            if(j != m - 1) sub += abs(x[j + 1] - x[j]);
        }
        for(int j : v[i - 1]){
            x[j] = i;
        }
        for(int j : v[i]){
            x[j] = 0;
        }
        ll add = 0;
        for(int j : v[i - 1]){
            if(j != 0) add += abs(x[j] - x[j - 1]);
            if(j != m - 1) add += abs(x[j + 1] - x[j]);
        }
        for(int j : v[i]){
            if(j != 0) add += abs(x[j] - x[j - 1]);
            if(j != m - 1) add += abs(x[j + 1] - x[j]);
        }
        s += add - sub;
        cout << s << " ";
    }
    cout << endl;
}