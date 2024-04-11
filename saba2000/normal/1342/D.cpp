#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> ans[200009];
int a[200009],f[200009];
int c[200009];
main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        f[a[i]]++;
    }
    for(int i = 1; i <= k; i++){
        scanf("%d", &c[i]);
    }
    int j = 0;
    for(int i = k; i >= 1; i--){
        if(c[i] != c[i+1]) j = 0;
        while(f[i]){
            while(ans[j].size() >= c[i]) j++;
            ans[j].push_back(i);
            f[i]--;
        }
    }
    j = 0;
    while(ans[j].size()) j++;
    cout<<j<<endl;
    for(int i = 0; i < j; i++){
        printf("%d ",ans[i].size());
        for(int x : ans[i]) printf("%d ", x);
        printf("\n");
    }


}
/*
x % a == (x % b)


*/