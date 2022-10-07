#include<bits/stdc++.h>
using namespace std;
int a[200009];
int f[200009];
int g[200009];
main(){
    int p, n;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int x = a[n] - n;
    for(int i = 1; i <= n; i++){
        a[i] -= x;
        a[i] = max(a[i], 1);
        f[a[i]]++;

    }
    for(int i = 1; i <= n; i++){
        f[i] += f[i-1];
    }
    for(int i = 1; i <= n; i++){
        int z = f[i] - i+1;
        g[(p+1-z%p)%p] = i;
    }
    vector<int> ans;
    for(int i = 1; i <= p-1; i++)
        if(i > g[i]) ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int y : ans)
        cout<<x+y<<" ";
    cout<<endl;


}