#include<bits/stdc++.h>
using namespace std;
int x[1009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        for(int i =1 ; i <= n; i++){
            cin>>x[i];
        }
        for(int i =1 ; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                s.insert(abs(x[i]-x[j]));
            }
        }
        cout<<s.size()<<endl;
    }

}