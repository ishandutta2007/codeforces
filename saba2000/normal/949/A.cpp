#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int f[200009];
vector<int> v[200009];
int cnt=0;
main(){
    string s;
    cin >> s;
    set<int > Y;
    set<int > N;
    for (int i = 0; i <s.size(); i++){
        if(s[i] == '1'){
            if(Y.size() ==0){
                cout << -1 << endl;
                return 0;
            }
            int x = *Y.begin();
            v[x].push_back(i+1);
            Y.erase(Y.begin());
            N.insert(x);
        }
        else
        {
            if(N.size() == 0){
                v[cnt] .push_back(i+1);
                Y.insert(cnt);
                cnt++;
            }
            else
            {
                int x = *N.begin();
                v[x].push_back(i+1);
                N.erase(N.begin());
                Y.insert(x);
            }
        }
    }
    if(N.size()) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
    for (int i=0; i < cnt; i++){
    cout << v[i].size() <<" ";
    for (int j=0; j <v[i].size(); j++)
        cout << v[i][j] << " ";
    cout << endl;
    }

}