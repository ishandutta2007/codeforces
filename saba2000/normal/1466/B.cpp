#include<bits/stdc++.h>
using namespace std;
int x[100009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        for(int i =1 ; i <= n; i++){
            cin>>x[i];
            if(x[i] <= x[i-1] && i > 1) x[i]++;

            s.insert(x[i]);
        }

        cout<<s.size()<<endl;
    }

}