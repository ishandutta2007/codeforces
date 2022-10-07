#include<bits/stdc++.h>
using namespace std;
int a[200009];
int b[200009];
main(){

    int n;
    cin >> n;
    for(int i =1 ; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = a[i] - a[i-1];
    }
    vector<int> ans;
    for(int k = 1; k <= n; k++){
        int fl = 1;
        for(int j = k +1; j <= n; j++)
            if(b[j] != b[j-k]) fl =0;
        if(fl) ans.push_back(k);
    }
    cout<<ans.size()<<endl;
    for(int x:ans)
        cout<<x<<" ";
    cout<<endl;
}