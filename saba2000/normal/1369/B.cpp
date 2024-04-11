#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
            int n;
    cin>>n;
        string s;
        cin >>s ;
        int j = 0;
        while(j < s.size() && s[j] == '0') j++;
        int k = 0;
        while(k < s.size() && s[s.size()-1-k] == '1') k++;
        for(int i = 0; i < j;i++)
            cout<<'0';
        if(j + k < s.size()) cout<<'0';
        for(int i = 0; i < k; i++)
            cout<<'1';
        cout<<endl;
    }



}