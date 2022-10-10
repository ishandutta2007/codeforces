#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%k!=0){
        cout<<"No\n";
        return 0;
    }
    int parcial = sum/k;
    vector<int> ans;
    //cout<<"Yes\n";
    int aux=0;
    int cont=0;
    for(int i=0;i<n;i++){
        aux+=arr[i];
        cont++;
        if(aux==parcial){
            ans.push_back(cont);
            cont=0;
            aux=0;
        }
        else if(aux>parcial){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<ans.size();i++){
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}