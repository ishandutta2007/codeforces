#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    long long X,d;
    cin >> X >> d;
    vector<long long> ans;
    for (long long i = 0; i < 31; i++){
        if((1<<i)&X){
            for (long long j = 0; j < i; j++){
                ans.push_back(i*(2*d)+1);
            }
            ans.push_back(i*(2*d)+d+1);
        }
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++){
        cout << ans[i] <<" ";
    }
    cout << endl;

}