#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009];
vector<int> ans[3000009];
main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if(c == 'L') a[i] = 0;
        else a[i] = 1;
    }
    int inv = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i] > a[j]) inv++;
        }
    }
    if(inv < k) {
        cout <<-1<<endl;
        return 0;
    }
    queue<int> q;
    for(int i = 1; i <= n-1; i++)
        if(a[i] > a[i+1]) q.push(i);
    int c = 0;
    while(k){
        int y = max(1,min((int)q.size(), inv - k + 1));
        while(y--){
            int x = q.front();
            q.pop();
            swap(a[x], a[x+1]);
            ans[c].push_back(x);
            inv--;
            if(x + 1 < n && !a[x+2]) q.push(x+1);
            if(x > 1 && a[x-1]) q.push(x-1);
        }
        k--;
        c++;
        if(inv < k){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(inv) {
        cout<<-1<<endl;
        return 0;
    }
    for(int i =0 ; i < c; i++){
        printf("%d ", ans[i].size());
        for(int x : ans[i])
            printf("%d ", x);
        printf("\n");
    }
}