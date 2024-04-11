#include<bits/stdc++.h>
using namespace std;
vector<int> v[100009];
main(){
    int n;
    cin >> n;
    if(n == 2){
        cout<<"Yes\n1\n1 2\n";
        return 0;
    }
    for(int i = 0; i < n -  1; i++){
            int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int nl = 0;
    vector<int> L;
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 1) {
            nl++;
            L.push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i].size() == nl){
            cout<<"Yes"<<endl;
            cout<<nl<<endl;
            for(int  j = 0; j < L.size(); j++)
                cout<<L[j]<<" "<<i<<endl;
            return 0;
        }

    }
    cout<<"No"<<endl;
    return 0;


}