#include<bits/stdc++.h>
using namespace std;
int sp[200009], A[200009], B[200009], f[200009];
vector<int> v[200009];
main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int a;
        scanf("%d", &a);
        sp[a] = 1;
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    f[1] =1;
    while(q.size()){
        int x= q.front();
        q.pop();
        for(int y : v[x])
            if(!f[y])
                A[y] = A[x] + 1,
                q.push(y),
                f[y] = 1;
    }
    q.push(n);
    for(int i = 1; i <= n; i++)
        f[i] = 0;
    f[n] =1;
    while(q.size()){
        int x= q.front();
        q.pop();
        for(int y : v[x])
            if(!f[y])
                B[y] = B[x] + 1,
                q.push(y),
                f[y] = 1;
    }
    //min(A[x] -B[x], A[y] -B[y]) +B[x]+B[y]
    vector<pair<int,int> > v;
    for(int i = 1; i <= n; i++){
        if(sp[i]) v.push_back({A[i] - B[i], i});
    }
    sort(v.rbegin(), v.rend());
    int maxB = B[v[0].second], ans = 0;
    for(int i = 1; i <v.size(); i++){
        int x = v[i].second;
        ans = max(ans, min(A[n], A[x] + maxB+1));
        maxB = max(maxB, B[x]);
    }
    cout<<ans<<endl;


}