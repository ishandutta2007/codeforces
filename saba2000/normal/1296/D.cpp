#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<int,int>,int> M;
main(){
    int n,a,b,k;
    cin >> n >> a >> b>> k;
    vector<int> v;
    for(int i = 0; i <n; i++){
        int h;
        cin>>h;

        h = (h-1) % (a+b)+1;
        v.push_back((h+a-1)/a-1);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        k -= v[i];
        if(k < 0) {cout<<i<<endl; return 0;}
    }
    cout<<n<<endl;

}