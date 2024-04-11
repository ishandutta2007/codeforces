#include<bits/stdc++.h>
using namespace std;
int l[20009], r[20009];
pair<int,int> T[2000];
int C[2009];
main(){
    int n;
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> l[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        T[i] = {l[i]+r[i],i};
    }
    sort(T+1, T+n+1);
    int cnt = n;
    for(int i = 1; i <= n; i++){
        if(T[i].first > T[i-1].first) cnt--;
        C[T[i].second] = cnt;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++)
            if(C[j] > C[i]) l[i]--;
        for(int j = i+1; j <=n; j++)
            if(C[j] > C[i]) r[i]--;
        if(l[i]!=0 || r[i]!=0){
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++)
        cout<<C[i]<<" ";
    cout<<endl;

}