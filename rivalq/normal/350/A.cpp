#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int co[n],wr[m];
    int minc,maxc=0;
    cin>>minc;
    for(int i=1;i<n;i++){
        int t; cin>>t; co[i]=t;
        if(minc>t) minc=t;
        if(maxc<t) maxc=t;
    }
    int minw;
    cin>>minw;
    for(int i=1;i<m;i++){
        int t; cin>>t; wr[i]=t;
        if(minw>t) minw=t;
    }
    int v=max(minc*2,maxc);
    if(v<minw) cout<<v<<endl;
    else  cout<<-1<<endl;

}