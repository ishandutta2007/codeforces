#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[102];
    vector<int> v[102];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        s[i]--;
        v[s[i]].push_back(i);
    }
    int e = 0;
    for(int i = 0; i < 100; i++){
        if((int)v[i].size() == 1) e++;
    }
    char ans[102];
    if(e % 2 == 0){
        cout << "YES" << endl;
        int j = 0;
        for(int i = 0; i < 100; i++){
            if(j < e / 2){
                for(int x : v[i]) ans[x] = 'A';
            }
            else{
                for(int x : v[i]) ans[x] = 'B';
            }
            if((int)v[i].size() == 1) j++;
        }
    }
    else{
        int l = 0;
        for(; l < 100; l++){
            if((int)v[l].size() >= 3) break;
        }
        if(l == 100){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        int j = 0;
        for(int i = 0; i < 100; i++){
            if(i == l){
                for(int x : v[i]) ans[x] = 'B';
                ans[v[i][0]] = 'A';
                continue;
            }
            if(j < e / 2){
                for(int x : v[i]) ans[x] = 'A';
            }
            else{
                for(int x : v[i]) ans[x] = 'B';
            }
            if((int)v[i].size() == 1) j++;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
}