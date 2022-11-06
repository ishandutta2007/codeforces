#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    int k=n+m;
    vector<int>x(k);
    for(int i=0;i<k;i++){
        cin>>x[i];
    }
    vector<int>t(k);
    for(int i=0;i<k;i++){
        cin>>t[i];
    }
    vector<int>tx;
    for(int i=0;i<k;i++){
        if(t[i]==1){
            tx.push_back(x[i]);
        }
    }
    vector<int>c(m,0);
    for(int i=0;i<k;i++){
        if(t[i]==0){
            if (tx[m-1]<x[i]){
                c[m-1]++;
            }else{
                if(tx[0]>x[i]){
                    c[0]++;
                }else{
                    int l=0;
                    int r=m-1;
                    while(r-l>1){
                        int mid=(l+r)/2;
                        if(tx[mid]<x[i]){
                            l=mid;
                        }else{
                            r=mid;
                        }
                    }
                    if(abs(x[i]-tx[l])<=abs(x[i]-tx[l+1])){
                        c[l]++;
                    }else{
                        c[l+1]++;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}