#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int, int> m;
    int quality[n]; 
    for(int i=0;i<n;i++){
        int p,q;
        cin>>p>>q;
        m.insert({p,q});
        quality[i]=q;
    }
    int i=0;
    sort(quality,quality+n);
    for(auto itr=m.begin();itr!=m.end();++itr){
        if(quality[i]!=itr->second)
        {
            cout<<"Happy Alex";
            return 0;
        }
        else{
            i++;
        }
    }
    cout<<"Poor Alex";
}