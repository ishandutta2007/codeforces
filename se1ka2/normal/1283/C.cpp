#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f[200005];
    bool b[200005]{0};
    for(int i = 1; i <= n; i++){
        cin >> f[i];
        b[f[i]] = true;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) if(f[i] == 0 && !b[i]){
        v.push_back(i);
        b[i] = true;
    }
    for(int i = 1; i < (int)v.size(); i++) f[v[i]] = v[i - 1];
    if(v.size()) f[v[0]] = v.back();
    int i = 1, j = 1;
    while(i <= n && j <= n){
        if(f[i] == 0){
            while(b[j]) j++;
            f[i] = j;
            if(v.size() == 1) swap(f[i], f[v[0]]);
            j++;
        }
        i++;
    }
    for(int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << endl;
}