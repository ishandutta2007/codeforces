#include<bits/stdc++.h>
using namespace std;
vector<long long> v[109];
main (){
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++){
        long long a,b;
        scanf("%lld", &a);b=a;
        int  k= 0;
        while(a%2==0) k++,a/=2;
        v[k].push_back(b);
    }
    int m = 0;
    for(int i = 0; i < 70; i++){
        if(v[i].size() > v[m].size()) m= i;
    }
    cout<<n-v[m].size()<<endl;
    for(int i = 0; i  < 70; i++)
        if(i!=m) for(long long x : v[i]) printf("%lld ", x);
}