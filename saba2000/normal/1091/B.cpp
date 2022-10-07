#include<bits/stdc++.h>
using namespace std;
pair<int,int> x[1009], a[1009];
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i].first>>x[i].second;
        
    }
    for(int i = 0; i < n; i++){
        cin >> a[i] .first>>a[i].second;
        a[i].first=-a[i].first;
        a[i].second = -a[i].second;
    }
    sort(x,x +n);
    sort(a,a +n);
    cout<<x[0].first -a[0].first << " "<<x[0].second-a[0].second<<endl;
    
}