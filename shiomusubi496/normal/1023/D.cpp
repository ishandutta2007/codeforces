#include<bits/stdc++.h>
#define int long long
using namespace std;
struct BinaryIndexedTree{
    int n;
    std::vector<int>dat;
    BinaryIndexedTree(int N){
        n=1;
        while(n<N)n*=2;
        dat.resize(n+1);
    }
    void add(int i,int x){
        ++i;
        while(i<=n){
            dat[i]+=x;
            i+=(i&-i);
        }
    }
    int sum(int i){
        int s=0;
        while(i>0){
            s+=dat[i];
            i-=(i&-i);
        }
        return s;
    }
    int sum(int x,int y){
        return sum(y)-sum(x);
    }
};
signed main(){
    int n,q; cin>>n>>q;
    vector<int> a(n);
    vector<vector<int>> b(q);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i])b[a[i]-1].push_back(i);
    }
    BinaryIndexedTree BIT(n);
    for(int i=0;i<q;i++){
        if(b[i].size()==0)continue;
        if(BIT.sum(b[i].front(),b[i].back()))return puts("NO"),0;
        for(int j:b[i])BIT.add(j,1);
    }
    if(b[q-1].size()==0){
        bool ok=false;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                a[i]=q;
                ok=true;
                break;
            }
        }
        if(!ok)return puts("NO");
    }
    for(int i=1;i<n;i++){
        if(a[i]==0)a[i]=a[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]==0)a[i]=a[i+1];
    }
    puts("YES");
    for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];
}