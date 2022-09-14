#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n+1,0),ra,rb;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    int yes,noa,nob;
    for(int i=1;i<=n;i++){
        if(c[i]==0)
            noa = i;
        if(c[i]==2)
            yes=i;
    }
    for(int i=0;i<n;i++){
        if(a[i]==yes)
            ra.push_back(i);
    }
    c=vector<int>(n+1,0);
    for(int i=0;i<n;i++){
        cin>>b[i];
        c[b[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0)
            nob = i;
        if(c[i]==2)
            yes=i;
    }
    for(int i=0;i<n;i++){
        if(b[i]==yes)
            rb.push_back(i);
    }
    int cc=0;
    for(int i=0;i<n;i++)
        if(a[i]==b[i])
            cc++;
    if(cc==n-1){
        if(a[ra[0]]!=b[ra[0]])
            a[ra[0]]=noa;
        else if(a[ra[1]]!=b[ra[1]])
            a[ra[1]]=noa;
    }
    else{
        if(b[ra[0]]==noa)
            a[ra[0]]=noa;
        else a[ra[1]]=noa;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}